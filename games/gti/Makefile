# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gti
PORTVERSION=	1.1.0
CATEGORIES=	games

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Just a silly git launcher, basically. Inspired by sl

USE_GITHUB=	yes
GH_ACCOUNT=	rwos
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	5afb520

MAN6=	${PORTNAME}.6

PLIST_FILES=	bin/${PORTNAME}

GTI_SPEED?=	50
CFLAGS+=	-DGTI_SPEED=${GTI_SPEED}

pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} " You can change the speed of the car at compile time."
	@${ECHO_MSG} " For example: \"make GTI_SPEED=100\" # default is 50"
	@${ECHO_MSG}

do-build:
	@${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN6} ${MANPREFIX}/man/man6

.include <bsd.port.mk>
