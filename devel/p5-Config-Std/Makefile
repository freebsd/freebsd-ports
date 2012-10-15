# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Config-Std
DISTVERSIONPREFIX=	v
DISTVERSION=	0.0.4
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Load and save configuration files in a standard format

RUN_DEPENDS=	p5-Class-Std>=0:${PORTSDIR}/devel/p5-Class-Std

PERL_CONFIGURE=	YES

MAN3=		Config::Std.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500900
RUN_DEPENDS+=	p5-version>=0:${PORTSDIR}/devel/p5-version
.endif

.include <bsd.port.post.mk>
