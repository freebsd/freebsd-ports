# Created by: James FitzGibbon <jfitz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBI
PORTVERSION=	1.636
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 Database Interface, required for DBD::* modules

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

OPTIONS_DEFINE=	PROXY
PROXY_DESC=	Build DBI::Proxy

CONFLICTS=	p5-DBI-1.3*

USES=		perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	dbixs_rev.pl

PROXY_BUILD_DEPENDS=	p5-PlRPC>=0.2001:net/p5-PlRPC
PROXY_RUN_DEPENDS=	p5-PlRPC>=0.2001:net/p5-PlRPC

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DBI/DBI.so

.include <bsd.port.mk>
