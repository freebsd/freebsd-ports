# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	ssocr
PORTVERSION=	2.21.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.unix-ag.uni-kl.de/~auerswal/ssocr/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	CLI to recognize digits of a seven segment display

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		gmake tar:bzip2

PLIST_FILES=	bin/ssocr \
		man/man1/ssocr.1.gz

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
