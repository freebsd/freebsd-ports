# New ports collection makefile for:	gti
# Date created:		2012-08-16
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gti
PORTVERSION=	1.0.4
CATEGORIES=	games

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Just a silly git launcher, basically. Inspired by sl

USE_GITHUB=	yes
GH_ACCOUNT=	rwos
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	e16ca0b

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
