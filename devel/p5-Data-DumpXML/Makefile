# New ports collection makefile for:	Data::DumpXML
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Data-DumpXML
PORTVERSION=	1.05
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca
COMMENT=	Dump arbitrary data structures as XML

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Array/RefElem.pm:${PORTSDIR}/misc/p5-Array-RefElem \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Data::DumpXML.3 \
		Data::DumpXML::Parser.3

.include <bsd.port.mk>
