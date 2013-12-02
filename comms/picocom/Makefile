# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	picocom
PORTVERSION=	1.7
CATEGORIES=	comms
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Dumb Terminal Emulator

ALL_TARGET=	picocom
USES=		gmake

PLIST_FILES=	bin/picocom man/man8/picocom.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/
.include <bsd.port.mk>
