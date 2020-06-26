# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	DBIWrapper
PORTVERSION=	0.30
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	SF
PKGNAMEPREFIX=	p5-
DISTNAME=	libdbiwrapper-perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for generic DBI database access

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
		p5-DateTime-HiRes>=0:devel/p5-DateTime-HiRes \
		p5-IO-Stringy>=0:devel/p5-IO-Stringy \
		p5-Spreadsheet-WriteExcel>=0:textproc/p5-Spreadsheet-WriteExcel \
		p5-XML-LibXML>=0:textproc/p5-XML-LibXML \
		p5-XML-SAX>=0:textproc/p5-XML-SAX
TEST_DEPENDS=	p5-DBD-Pg>=0:databases/p5-DBD-Pg \
		p5-DateTime>=0:devel/p5-DateTime

USES=		perl5 shebangfix
USE_PERL5=	configure
NO_ARCH=	yes

SHEBANG_FILES=	parse_test.pl

.include <bsd.port.mk>
