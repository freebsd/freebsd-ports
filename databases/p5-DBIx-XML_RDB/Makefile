# Created by: vanilla
# $FreeBSD$

PORTNAME=	DBIx-XML_RDB
PORTVERSION=	0.05
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for creating XML from existing DBI datasources

BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-XML-Parser>=0:textproc/p5-XML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	sql2xml.pl xml2sql.pl
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>
