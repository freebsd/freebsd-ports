# New ports collection makefile for:	polygraph
# Date created:         3 March 1999
# Whom:                 Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	polygraph
PORTVERSION=	2.7.6
CATEGORIES=	benchmarks www
MASTER_SITES=	http://www.web-polygraph.org/downloads/srcs/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	adrian@FreeBSD.org
COMMENT=	A benchmarking tool for Web proxies


IS_INTERACTIVE=	yes

GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.pre.mk>

BROKEN=		"Does not compile"

.include <bsd.port.post.mk>
