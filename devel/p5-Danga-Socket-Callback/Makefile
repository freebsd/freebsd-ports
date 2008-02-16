# New ports collection makefile for:	p5-Danga-Socket-Callback
# Date created:		2008-01-30
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	Danga-Socket-Callback
PORTVERSION=	0.01200
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Danga
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Use Danga::Socket From Callbacks

BUILD_DEPENDS=	p5-Danga-Socket>=0:${PORTSDIR}/devel/p5-Danga-Socket
RUN_DEPENDS=	p5-Danga-Socket>=0:${PORTSDIR}/devel/p5-Danga-Socket

PERL_CONFIGURE=	yes

MAN3=		Danga::Socket::Callback.3

.include <bsd.port.mk>
