# ex:ts=8
# New ports collection makefile for:	mmake
# Date created:			Sep 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mmake
PORTVERSION=	2.2.1
PORTREVISION=	1
CATEGORIES=	java devel
MASTER_SITES=	http://www.tildeslash.com/mmake/dist/

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Create a Makefile for Your Java files, ready to compile

BUILD_DEPENDS=	jikes:${PORTSDIR}/java/jikes
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PERL5=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
NO_BUILD=	yes

MAN1=	mmake.1

.include <bsd.port.mk>
