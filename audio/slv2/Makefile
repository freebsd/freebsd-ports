# Created by: xaimus <xaimus@gmail.com>
# $FreeBSD$

PORTNAME=	slv2
PORTVERSION=	0.6.6
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://download.drobilla.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LV2 Application Support Library

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		fails to configure
DEPRECATED=	Broken for more than 5 months
EXPIRATION_DATE=	2020-01-10

BUILD_DEPENDS=	lv2>=1.14.0_1:audio/lv2
LIB_DEPENDS=	libjack.so:audio/jack \
		librdf.so:textproc/redland

USES=		pkgconfig tar:bzip2 waf
USE_LDCONFIG=	yes

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
