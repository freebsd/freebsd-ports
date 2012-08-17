# New ports collection makefile for:	gti
# Date created:		2012-08-16
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gti
PORTVERSION=	1.0.3
CATEGORIES=	games
MASTER_SITES=	https://github.com/rwos/gti/tarball/master/
DISTNAME=	${GITNAME}-v${PORTVERSION}-g${GITVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Just a silly git launcher, basically. Inspired by sl

GITUSER=	rwos
GITREPONAME=	${PORTNAME}
GITNAME=	${GITUSER}-${GITREPONAME}
GITVERSION=	0b77b60

WRKSRC=	${WRKDIR}/${GITNAME}-${GITVERSION}

FETCH_ARGS=	-pRr
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
