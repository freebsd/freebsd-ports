# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	PkgConfig
PORTVERSION=	0.12026
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PLICEASE
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Pure-Perl Core-Only replacement for pkg-config

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

PORTSCOUT=	limit:^[0-9\.]*$$

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5 pkgconfig

.include <bsd.port.mk>
