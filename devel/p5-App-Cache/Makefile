# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	App-Cache
PORTVERSION=	0.37
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy application-level caching

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Class-Accessor-Chained>=0:devel/p5-Class-Accessor-Chained \
		p5-File-Find-Rule>=0:devel/p5-File-Find-Rule \
		p5-File-HomeDir>=0:devel/p5-File-HomeDir \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-libwww>=0:www/p5-libwww

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
