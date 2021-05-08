# Created by: Martin Wilke <miwi@FreeBSD.org>

PORTNAME=	picocom
DISTVERSION=	3.1
CATEGORIES=	comms

MAINTAINER=	rmm1.bob@gmail.com
COMMENT=	Dumb Terminal Emulator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	npat-efault

PLIST_FILES=	bin/picocom man/man1/picocom.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
