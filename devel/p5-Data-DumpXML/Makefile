# New ports collection makefile for:	Data::DumpXML
# Date created:				31 Dec 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Data-DumpXML
PORTVERSION=	1.06
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Dump arbitrary data structures as XML

RUN_DEPENDS=	p5-Array-RefElem>=0.01:${PORTSDIR}/misc/p5-Array-RefElem \
		p5-XML-Parser>=2:${PORTSDIR}/textproc/p5-XML-Parser
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Data::DumpXML.3 \
		Data::DumpXML::Parser.3

.include <bsd.port.mk>
