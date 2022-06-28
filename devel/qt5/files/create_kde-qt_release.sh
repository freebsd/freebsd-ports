#!/bin/sh

# Creates and updates a git checkout in ${BASE_DIRECTORY}
# for the given KDE Qt repository ${PROJECT}.
# After that, a new distfile for the ports tree is created.

DIST="$1"
PROJECT=qt"${DIST}"
BASE_DIRECTORY="$2"
# Version of Qt we want
VERSION="$3"
ORIGIN_TAG="$4"

# Remote KDE git repository
REPO="https://invent.kde.org/qt/qt/${PROJECT}.git"
# Local checkout
CHECKOUT="${BASE_DIRECTORY}/${PROJECT}"

# KDE-Qt branch
BRANCH=kde/5.15

# Make sure we can use ${BASE_DIRECTORY}
if [ ! -d "${BASE_DIRECTORY}" ] || [ ! -w "${BASE_DIRECTORY}" ] ; then
	echo "Directory '${BASE_DIRECTORY}' does not exist"
	exit 1
fi

# Init a new git checkout if it is missing
if [ ! -d "${CHECKOUT}" ] ; then
	git -C "${BASE_DIRECTORY}" clone "${REPO}"
fi

# Update the checkout of the required branch
git -C "${CHECKOUT}" checkout "${BRANCH}" && git -C "${CHECKOUT}" pull --ff-only --rebase --autostash
if [ $? -ne 0 ] ; then
	echo "Failed to update ${CHECKOUT}"
	exit 1
fi

# Count number of patches added by KDE
PATCH_COUNT=$(git -C ${CHECKOUT} rev-list --count ${ORIGIN_TAG}..origin/${BRANCH})

# Setup information for the distfile
DISTNAME="kde-${PROJECT}-${VERSION}p${PATCH_COUNT}"
DISTFILE="${BASE_DIRECTORY}/${DISTNAME}.tar.xz"

# Tar and compress distfile
git -C ${CHECKOUT} archive --format=tar --prefix="${DISTNAME}/" HEAD | xz > "${DISTFILE}"
if [ $? -ne 0 ] ; then
	echo "Failed to create tarball ${DISTFILE}"
	exit 1
fi

# Printout information required in qt-dist.mk
echo -e "Distfile:\t${DISTFILE}\n_KDE_${DIST}=\t${PATCH_COUNT}"
