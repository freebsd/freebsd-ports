# Ports collection makefile for: Japanese Font Setup for math/ngraph
# Date created:		6 December 1999
# Whom:			Yoshiro MIHIRA <sanpei@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ngraph-fonts
PORTVERSION=	1.0
CATEGORIES=	japanese math x11-fonts
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Japanese Font Setup for math/ngraph

RUN_DEPENDS= \
	${X11BASE}/lib/X11/fonts/local/kanji18.pcf.gz:${PORTSDIR}/japanese/kanji18 \
	${X11BASE}/lib/X11/fonts/local/kanji26.pcf.gz:${PORTSDIR}/japanese/kanji26 \
	mkfontdir:${X_CLIENTS_PORT}

USE_X_PREFIX=	yes

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.mk>
