# Created by: xaimus <xaimus@gmail.com>
# $FreeBSD$

PORTNAME=	lv2core
PORTVERSION=	6.0
CATEGORIES=	audio
MASTER_SITES=	http://lv2plug.in/spec/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LV2 Core Package

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS_INSTALL=	lv2

USES=		pkgconfig python:build tar:bzip2 waf

post-patch:
	@${REINPLACE_CMD} -e '/autowaf.build_pc/s|^|#|' ${WRKSRC}/wscript
	@(cd ${WRKSRC} && ${SED} -e \
		's|@PREFIX@|${PREFIX}| ; \
		 s|@EXEC_PREFIX@|${PREFIX}| ; \
		 s|@LIBDIR@|${PREFIX}/lib| ; \
		 s|@INCLUDEDIR@|${PREFIX}/include| ; \
		 s|@LV2CORE_VERSION@|${PORTVERSION}|' < lv2core.pc.in > lv2core.pc)

post-install:
	${INSTALL_DATA} ${WRKSRC}/lv2core.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig

.include <bsd.port.mk>
