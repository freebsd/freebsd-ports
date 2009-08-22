# New ports collection makefile for:	dbiwrapper
# Date Created:				30 June 2001
# Whom:					Pete Fritchman <petef@databits.net>
#
# $FreeBSD$
#

PORTNAME=	DBIWrapper
PORTVERSION=	0.24
CATEGORIES=	databases perl5
MASTER_SITES=	SF
PKGNAMEPREFIX=	p5-
DISTNAME=	libdbiwrapper-perl-${PORTVERSION}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension for generic DBI database access

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIWrapper.3 DBIWrapper::ResultSet.3 DBIWrapper::XMLParser.3

.include <bsd.port.mk>
