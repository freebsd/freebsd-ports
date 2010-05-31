# New ports collection makefile for:	BIG5/GB-ized VFlib
# Date created:		11 Dec 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vflib
PORTVERSION=	${VFLIB_VERSION}
PORTREVISION=	4
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

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake

VFLIB_VERSION=	2.25.6
PLIST_SUB=	VFLIB_VERSION=${VFLIB_VERSION}

DATADIR=	${PREFIX}/share/VFlib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-freetype \
		--with-freetype-includedir=${LOCALBASE}/include/freetype1/freetype \
		--with-freetype-libdir=${LOCALBASE}/lib
USE_FREETYPE=	yes
USE_XORG=	x11 xext
USE_LDCONFIG=	yes
USE_GETTEXT=	yes

.include <bsd.port.pre.mk>

pre-patch:
	@${SED} -e "s;%%LOCALBASE%%;${LOCALBASE};g" -e "s;%%X11BASE%%;${LOCALBASE};g" ${DISTDIR}/zh-vfontcap.in > ${WRKSRC}/vfontcap

post-patch:
	@${REINPLACE_CMD} -e "s,varargs.h,stdarg.h," ${WRKSRC}/tools/disol.c
	@${REINPLACE_CMD} -e "s,^vflib2_version=.*,vflib2_version='${VFLIB_VERSION}'," ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s,echo aout,echo elf," ${WRKSRC}/ltconfig

post-install:
	@(cd ${WRKSRC}/tools; \
		${INSTALL_SCRIPT} fmtest disol kban vfperf vftest ${PREFIX}/bin)
	@(cd ${WRKSRC}; \
		${MKDIR} ${DATADIR}/${VFLIB_VERSION} ;\
		${CP} COPYING COPYING.LIB README.txt.JP_EUC \
		${DATADIR}/${VFLIB_VERSION})
	${MV} ${DATADIR}/${VFLIB_VERSION}/VF.h ${PREFIX}/include

.include <bsd.port.post.mk>
