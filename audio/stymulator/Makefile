# New ports collection makefile for:	stymulator
# Date created:				27 Mar 2010
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	stymulator
DISTVERSION=	0.21a
CATEGORIES=	audio
MASTER_SITES=	http://atariarea.krap.pl/stymulator/files/ \
		CRITICAL
DISTNAME=	STYMulator-${DISTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line Yamaha YM2149 (.ym) chiptune player

USE_DOS2UNIX=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/src

PLIST_FILES=	bin/ym2wav bin/ymplayer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ym2wav ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ymplayer ${PREFIX}/bin

.include <bsd.port.mk>
