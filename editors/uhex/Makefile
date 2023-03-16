PORTNAME=	uhex
PORTVERSION=	1.0.4
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Simple and fast console hexadecimal editor
WWW=		https://uhex.sourceforge.net/

LICENSE=	BSD2CLAUSE

PLIST_FILES=	bin/${PORTNAME}

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} -DSWITCHCHAR=\'-\' \
		-DSWITCHSTR=\"-\" file.c io-curse.c uhex.c \
		-o ${PORTNAME} -lncurses

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
