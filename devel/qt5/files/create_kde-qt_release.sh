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
BRANCH="$5"

# Remote KDE git repository
REPO="https://invent.kde.org/qt/qt/${PROJECT}.git"
# Local checkout
CHECKOUT="${BASE_DIRECTORY}/${PROJECT}"

# Make sure we can use ${BASE_DIRECTORY}
if [ ! -d "${BASE_DIRECTORY}" ] || [ ! -w "${BASE_DIRECTORY}" ] ; then
	echo "Directory '${BASE_DIRECTORY}' does not exist"
	exit 1
fi

# Init a new git checkout if it is missing
if [ ! -d "${CHECKOUT}" ] ; then
	git -C "${BASE_DIRECTORY}" clone --recurse-submodules --no-remote-submodules "${REPO}"
fi

# Update the checkout of the required branch
git -C "${CHECKOUT}" fetch --tags && \
git -C "${CHECKOUT}" checkout "${BRANCH}" && \
git -C "${CHECKOUT}" pull --no-ff --rebase --autostash && \
git -C "${CHECKOUT}" submodule update --force --checkout

if [ $? -ne 0 ] ; then
	echo "Failed to update ${CHECKOUT}"
	exit 1
fi

# Count number of patches added by KDE
PATCH_COUNT=$(git -C ${CHECKOUT} rev-list --count ${ORIGIN_TAG}..origin/${BRANCH})

# Set up information for the distfile
DISTNAME="kde-${PROJECT}-${VERSION}p${PATCH_COUNT}"
DISTFILE_TAR="${BASE_DIRECTORY}/${DISTNAME}.tar"
DISTFILE="${DISTFILE_TAR}.xz"

# Tar and compress distfile if it does not exist
if [ ! -f "${DISTFILE}" ] ; then

	git -C ${CHECKOUT} archive --format=tar --prefix="${DISTNAME}/" HEAD --output ${DISTFILE_TAR} && \
	git -C ${CHECKOUT} submodule foreach --recursive "git archive --prefix="${DISTNAME}"/\$path/ --output=${BASE_DIRECTORY}/\$sha1.tar HEAD && tar -r --file=${DISTFILE_TAR} @${BASE_DIRECTORY}/\$sha1.tar && rm ${BASE_DIRECTORY}/\$sha1.tar" && \
	xz ${DISTFILE_TAR}

	if [ $? -ne 0 ] ; then
		echo "Failed to create tarball ${DISTFILE}"
		exit 1
	fi
else
	echo "Distfile already exists, skipping creation."
fi

# Print out information required in qt-dist.mk
echo -e "Distfile:\t${DISTFILE}\n_KDE_${DIST}=\t${PATCH_COUNT}"
