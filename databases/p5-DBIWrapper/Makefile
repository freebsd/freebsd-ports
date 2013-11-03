# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	DBIWrapper
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	SF
PKGNAMEPREFIX=	p5-
DISTNAME=	libdbiwrapper-perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for generic DBI database access

BUILD_DEPENDS=	p5-XML-LibXML>=0:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-SAX>=0:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Spreadsheet-WriteExcel>=0:${PORTSDIR}/textproc/p5-Spreadsheet-WriteExcel \
		p5-IO-stringy>=0:${PORTSDIR}/devel/p5-IO-stringy
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
