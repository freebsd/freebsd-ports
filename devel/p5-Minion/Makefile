# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Minion
PORTVERSION=	9.12
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Asynchronous job queue for Mojolicious

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Mojolicious>=8.12:www/p5-Mojolicious

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	PGSQL

PGSQL_BUILD_DEPENDS=	p5-Mojo-Pg>=4.0:databases/p5-Mojo-Pg
PGSQL_RUN_DEPENDS=	${PGSQL_BUILD_DEPENDS}

.include <bsd.port.mk>
