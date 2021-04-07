PORTNAME=	predict
PORTVERSION=	2.2.7
CATEGORIES=	comms astro hamradio
MASTER_SITES=	https://www.qsl.net/kd2bd/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Satellite tracking program for amateur radio satellites

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libasound.so:audio/alsa-lib

USES=		ncurses
INSTALL_TARGET=	install install.man

post-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/predict.h > ${WRKSRC}/predict.h
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/vocalizer.h > ${WRKSRC}/vocalizer/vocalizer.h
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' -e 's|%%STAGEDIR%%|${STAGEDIR}|g' \
		-e 's|%%CC%%|${CC}|g' -e 's|%%CFLAGS%%|${CFLAGS}|g' \
			${FILESDIR}/Makefile > ${WRKSRC}/Makefile

.include <bsd.port.mk>
