# New ports collection makefile for:	p5-Graph-ReadWrite
# Date created:				2004-08-12
# Whom:					arved
#
# $FreeBSD$

PORTNAME=	Graph-ReadWrite
PORTVERSION=	1.07
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Graph
PKGNAMEPREFIX=	p5-

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Reading and Writing a variety of graph file formats

BUILD_DEPENDS=	${SITE_PERL}/Graph/Base.pm:${PORTSDIR}/math/p5-Graph \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Graph::Reader.3 Graph::Writer::HTK.3 Graph::Writer::daVinci.3 \
	Graph::Writer::XML.3 Graph::Writer::Dot.3 Graph::Reader::HTK.3 \
	Graph::Reader::XML.3 Graph::Writer::VCG.3 Graph::Reader::Dot.3 \
	Graph::Writer.3

.include <bsd.port.mk>
