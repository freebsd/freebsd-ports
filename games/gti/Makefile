# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gti
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	GH GHC LOCAL/tota/${PORTNAME}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Just a silly git launcher, basically. Inspired by sl

USE_GITHUB=	yes
GH_ACCOUNT=	rwos
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	811998c

MAN6=	${PORTNAME}.6

PLIST_FILES=	bin/${PORTNAME}

GTI_SPEED?=	50
CFLAGS+=	-DGTI_SPEED=${GTI_SPEED}

NO_STAGE=	yes
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} " You can change the speed of the car at compile time."
	@${ECHO_MSG} " For example: \"make GTI_SPEED=100\" # default is 50"
	@${ECHO_MSG}

do-build:
	@${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MANPREFIX}/man/man6

.include <bsd.port.mk>
