# Created by: Peter Jeremy <peterjeremy@acm.org>
# $FreeBSD$

# Based on the OpenBSD port by:		Jasper Lievisse Adriaanse <jasper@openbsd.org>

PORTNAME=		mspdebug
PORTVERSION=		0.21
CATEGORIES=		devel
MASTER_SITES=		SF/${PORTNAME}

MAINTAINER=		peterjeremy@acm.org
COMMENT=		Debugger for use with MSP 430 MCUs

LICENSE=		GPLv2

MAN1=			mspdebug.1
USE_GMAKE=		yes

PLIST_FILES=		bin/mspdebug

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mspdebug ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mspdebug.man ${PREFIX}/man/man1/mspdebug.1

.include <bsd.port.mk>
