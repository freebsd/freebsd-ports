# New ports collection makefile for:    AbiWord
# Date created:         3 Mar 1999
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AbiWord
PORTVERSION=	${VERSION}
CATEGORIES=	editors
MASTER_SITES=	http://download.abisource.com/releases/${VERSION}/src/lf/
DISTNAME=	abi-${VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} expat-${VERSION}.tar.gz \
		unixfonts-${VERSION}.tar.gz wv-${VERSION}.tar.gz \
		libiconv-${VERSION}.tar.gz abidistfiles-${VERSION}.tar.gz

MAINTAINER=	wolman@cs.washington.edu

# unzip is needed during the installation process
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		png.3:${PORTSDIR}/graphics/png
RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

DIST_SUBDIR=	AbiWord

VERSION=	0.7.10
WRKSRC=		${WRKDIR}/abi-${VERSION}/src
USE_XLIB=	yes
USE_GMAKE=	yes
MAKE_ENV=	prefix="${PREFIX}"

.include <bsd.port.pre.mk>

# start by deleting some junk files that should never have been placed
# in the tar file
pre-build:
	cd ${WRKSRC} && ${RM} -f ../user/wp/help/en-US/images/?line.jpg
	cd ${WRKSRC} && ${RM} -f ../user/wp/help/en-US/images/?space.jpg

do-configure:
	@(cd ${WRKDIR}/wv && ./configure)

.include <bsd.port.post.mk>
