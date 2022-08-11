PORTNAME=	bpl+
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	LOCAL/max
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	B Plus file transfer protocol

PLIST_FILES=	bin/bp bin/bpl

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpl ${STAGEDIR}${PREFIX}/bin
	${LN} -sf bpl ${STAGEDIR}${PREFIX}/bin/bp

.include <bsd.port.mk>
