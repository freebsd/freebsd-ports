# New ports collection makefile for:	Data::DumpXML
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Data-DumpXML
PORTVERSION=	1.03
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	svenasse@polaris.ca

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Array/RefElem.pm:${PORTSDIR}/misc/p5-Array-RefElem \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

SITE_PERL=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}
PERL_CONFIGURE=	yes

MAN3=	Data::DumpXML.3 Data::DumpXML::Parser.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
