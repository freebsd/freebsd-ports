# New ports collection makefile for:	gti
# Date created:		2012-08-16
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gti
PORTVERSION=	0.0.2012.08.16
CATEGORIES=	games
MASTER_SITES=	https://github.com/rwos/gti/tarball/master/
DISTNAME=	${GITNAME}-${GITVERSION}

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Just a silly git launcher, basically. Inspired by sl

GITUSER=	rwos
GITREPONAME=	${PORTNAME}
GITNAME=	${GITUSER}-${GITREPONAME}
GITVERSION=	ef5c4d8

FETCH_ARGS=	-pRr
ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME}

do-build:
	@${CC} ${CFLAGS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
