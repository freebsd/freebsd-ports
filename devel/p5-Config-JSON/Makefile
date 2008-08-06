# New ports collection makefile for:	p5-Config-JSON
# Date created:		2008-07-31
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	Config-JSON
PORTVERSION=	1.1.4
CATEGORIES=	devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cherry@trombik.org
COMMENT=	A JSON based config file system

RUN_DEPENDS=	p5-Class-InsideOut>0:${PORTSDIR}/devel/p5-Class-InsideOut \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON

WRKSRC=		${WRKDIR}/Config-JSON

PERL_CONFIGURE=	Yes
MAN3=	Config::JSON.3

.include <bsd.port.mk>
