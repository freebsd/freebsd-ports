# Created by: Jov amutu@amutu.com
# $FreeBSD$

PORTNAME=	ora2pg
PORTVERSION=	18.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	amutu@amutu.com
COMMENT=	Oracle to PostgreSQL database schema converter

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-Class-DBI-Pg>=0:databases/p5-Class-DBI-Pg \
		p5-Class-DBI-mysql>=0:databases/p5-Class-DBI-mysql \
		p5-Class-DBI-Oracle>=0:databases/p5-Class-DBI-Oracle

RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_GITHUB=	yes
GH_ACCOUNT=	darold

do-patch:
	${REINPLACE_CMD} -e '/install_all :/,/};/s=$$CONFDIR=${STAGEDIR}${ETCDIR}=g' \
		-e '/install_all :/,/};/s=$$DOCDIR=${STAGEDIR}${DOCSDIR}=g' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
