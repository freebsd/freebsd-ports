# New ports collection makefile for:    AbiWord
# Date created:         3 Mar 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

# Note: this port cannot be built when the textproc/mswordview port is
# already installed, due to header file conflicts and the very broken
# AbiWord build system.

PORTNAME=	AbiWord
PORTVERSION=	0.7.12
CATEGORIES=	editors
MASTER_SITES=	http://download.abisource.com/releases/${PORTVERSION}/src/
DISTNAME=	abi-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} expat.tar.gz unixfonts.tar.gz \
		wv.tar.gz abidistfiles.tar.gz

MAINTAINER=	wolman@cs.washington.edu

# unzip is needed during the installation process
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	png.4:${PORTSDIR}/graphics/png \
		iconv.2:${PORTSDIR}/converters/iconv
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

DIST_SUBDIR=	AbiWord

WRKSRC=		${WRKDIR}/abi-${PORTVERSION}/src
USE_XLIB=	yes
USE_GMAKE=	yes
USE_GTK=	yes
MAKE_ENV=	prefix="${PREFIX}"

.include <bsd.port.pre.mk>

# start by deleting some junk files that should never have been placed
# in the tar file
pre-build:
	cd ${WRKSRC} && ${RM} -f ../user/wp/help/en-US/images/?line.jpg
	cd ${WRKSRC} && ${RM} -f ../user/wp/help/en-US/images/?space.jpg

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
