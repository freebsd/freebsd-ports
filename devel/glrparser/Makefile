# ex:ts=8
# Ports collection makefile for:	glrParser
# Date created:			Nov 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	glrparser
PORTVERSION=	1.4
CATEGORIES=	devel
MASTER_SITES=	http://nlp.fi.muni.cz/projekty/glr/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A parser works with the GLR(0) algorithm

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=		"Does not compile with gcc 3.4.2"
.endif

.include <bsd.port.post.mk>
