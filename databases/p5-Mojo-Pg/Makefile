# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Mojo-Pg
PORTVERSION=	4.15
CATEGORIES=	databases www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PostgreSQL integration for p5-Mojolicious

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBD-Pg>=3.5.1:databases/p5-DBD-Pg \
		p5-Mojolicious>=8.03:www/p5-Mojolicious \
		p5-SQL-Abstract>=1.86:databases/p5-SQL-Abstract

OPTIONS_DEFINE=	EXAMPLES

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTEXAMPLES=	*

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
