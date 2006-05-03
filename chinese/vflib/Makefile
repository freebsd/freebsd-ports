# New ports collection makefile for:	BIG5/GB-ized VFlib
# Date created:		11 Dec 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vflib
PORTVERSION=	${VFLIB_VERSION}
CATEGORIES=	chinese print
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/VFlib2/ \
		ftp://gull.se.hiroshima-u.ac.jp/pub/TypeHack/
DISTNAME=	VFlib2-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} zh-vfontcap.in
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/VFlib2/
PATCHFILES=	VFlib2-2.25.1-Chinese.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vector font library with free vector font, BIG5 and GB supported

BUILD_DEPENDS=	xmkmf:${X_IMAKE_PORT}

VFLIB_VERSION=	2.25.1
PLIST_SUB=	VFLIB_VERSION=${VFLIB_VERSION}

GNU_CONFIGURE=	yes
USE_FREETYPE=	yes
USE_XLIB=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-freetype \
		--with-freetype-includedir=${PREFIX}/include/freetype1/freetype \
		--with-freetype-libdir=${PREFIX}/lib

.include <bsd.port.pre.mk>

pre-patch:
	@${SED} -e "s;%%LOCALBASE%%;${LOCALBASE};g" -e "s;%%X11BASE%%;${X11BASE};g" ${DISTDIR}/zh-vfontcap.in > ${WRKSRC}/vfontcap

post-patch:
	${REINPLACE_CMD} -e "s,varargs.h,stdarg.h," ${WRKSRC}/tools/disol.c

pre-install:
	@(cd ${WRKSRC}/tools; \
	    ${INSTALL_SCRIPT} fmtest disol kban vfperf vftest ${PREFIX}/bin)
	@(cd ${WRKSRC}; \
	  ${MKDIR} ${PREFIX}/share/VFlib/${VFLIB_VERSION} ;\
	  ${CP} COPYING COPYING.LIB README.txt.JP_EUC \
		${PREFIX}/share/VFlib/${VFLIB_VERSION})

post-install:
	${MV} ${PREFIX}/share/VFlib/${VFLIB_VERSION}/VF.h ${PREFIX}/include

.include <bsd.port.post.mk>
