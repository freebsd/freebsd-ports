# New ports collection makefile for:	custom for mule
# Version required:	1.9962
# Date created:		27 December 1998
# Whom:			shige
#
# $FreeBSD$
#

MAINTAINER=	shige@FreeBSD.org

PATCHFILES=	custom-1.9962.patch
PATCH_SITES=	ftp://ftp.jpl.org/pub/elisp/semi-gnus-mule23@1934/
PATCH_DIST_STRIP= -p1

# This is a slave port.
PORTCLASS=	slave

MASTERDIR=	${.CURDIR}/../../editors/custom-emacs

# emacs port setup
EMACS_NAME=	mule
EMACS_PORT=	mule
EMACS_VER=	19.34
EMACS_LIBDIR=	share/${EMACS_NAME}
HAVE_COMMON_PORT= YES

# pkg/* files but PLIST are used in ${.CURDIR}
PKGDIR=		${.CURDIR}/pkg
PLIST=		${MASTERDIR}/pkg/PLIST

.include <${MASTERDIR}/Makefile>
