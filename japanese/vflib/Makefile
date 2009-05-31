# New ports collection makefile for:	vflib + FreeType
# Date created:		10 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vflib
PORTVERSION=	${VFLIB_VERSION}
PORTREVISION=	10
CATEGORIES=	japanese print
MASTER_SITES=	ftp://gull.se.hiroshima-u.ac.jp/pub/TypeHack/
DISTNAME=	VFlib2-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Vector font library

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake
RUN_DEPENDS=	${LOCALBASE}/share/font-sazanami/sazanami-mincho.ttf:${PORTSDIR}/japanese/font-sazanami

VFLIB_VERSION=	2.25.6
PLIST_SUB=	VFLIB_VERSION=${VFLIB_VERSION}

USE_XORG=	x11 xext
USE_FREETYPE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	autoconf:213
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-freetype \
		--with-freetype-includedir=${LOCALBASE}/include/freetype1/freetype \
		--with-freetype-libdir=${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/ltconfig

pre-install:
	@(cd ${WRKSRC}/tools; \
	    ${INSTALL_SCRIPT} fmtest disol kban vfperf vftest ${PREFIX}/bin)
	@(cd ${WRKSRC}; \
	  ${MKDIR} ${PREFIX}/share/VFlib/${VFLIB_VERSION} ;\
	  ${CP} COPYING COPYING.LIB README.txt.JP_EUC \
		${PREFIX}/share/VFlib/${VFLIB_VERSION} ;\
	  ${CP} -R jTeX ${PREFIX}/share/VFlib/${VFLIB_VERSION})

post-install:
	${MV} ${PREFIX}/share/VFlib/${VFLIB_VERSION}/VF.h ${PREFIX}/include

.include <bsd.port.mk>
