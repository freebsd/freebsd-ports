# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Minion
PORTVERSION=	5.09
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Asynchronous job queue for Mojolicious

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Mojolicious>=6.0:www/p5-Mojolicious
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	PGSQL

PGSQL_BUILD_DEPENDS=	p5-Mojo-Pg>=2.18:databases/p5-Mojo-Pg
PGSQL_RUN_DEPENDS=	${PGSQL_BUILD_DEPENDS}

.include <bsd.port.mk>
