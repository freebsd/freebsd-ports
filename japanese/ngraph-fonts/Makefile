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

RUN_DEPENDS= \
	${X11BASE}/lib/X11/fonts/local/kanji18.pcf.gz:${PORTSDIR}/japanese/kanji18 \
	${X11BASE}/lib/X11/fonts/local/kanji26.pcf.gz:${PORTSDIR}/japanese/kanji26

USE_X_PREFIX=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
RUN_DEPENDS+=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

NO_BUILD=	yes

do-install:	# empty

.include <bsd.port.post.mk>
