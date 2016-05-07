# Created by: xaimus <xaimus@gmail.com>
# $FreeBSD$

PORTNAME=	slv2
PORTVERSION=	0.6.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LV2 Application Support Library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/lv2.h:audio/lv2core
LIB_DEPENDS=	libjack.so:audio/jack \
		librdf.so:textproc/redland

USES=		pkgconfig tar:bzip2 waf
USE_LDCONFIG=	yes

.if defined(BATCH) || defined(PACKAGE_BUILDING)
MAKE_ARGS=	--verbose
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/pkgconfig/s|$${LIBDIRNAME}|libdata|' ${WRKSRC}/autowaf.py
	@${REINPLACE_CMD} -e \
		'/autowaf.build_dox/s|^|#| ; \
		 /HTMLDIR/s|^|#| ; \
		 /MANDIR/s|^|#|' ${WRKSRC}/wscript
	@${REINPLACE_CMD} -e \
		's|^#define _XOPEN_SOURCE .*||' ${WRKSRC}/src/plugin.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libslv2.so
.for file in lv2_inspect lv2_jack_host lv2_list lv2_simple_jack_host
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor

.include <bsd.port.mk>
