# New ports collection makefile for:   tuneradio
# Date created:        5 Febuary 2004
# Whom:                pozar
#
# $FreeBSD$
#

PORTNAME=	tuneradio
PORTVERSION=	1.3
CATEGORIES=	audio
MASTER_SITES=	http://www.lns.com/papers/tuneradio/

MAINTAINER=	pozar@lns.com
COMMENT=	A command line method of tuning a Brooktree FM tuner card

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
BROKEN=		"Does not compile on alpha 4.x"
.endif

.include <bsd.port.post.mk>
