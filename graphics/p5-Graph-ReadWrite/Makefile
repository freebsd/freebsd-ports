# Created by: arved
# $FreeBSD$

PORTNAME=	Graph-ReadWrite
PORTVERSION=	2.04
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Reading and Writing a variety of graph file formats

BUILD_DEPENDS=	p5-Graph>=0.50:${PORTSDIR}/math/p5-Graph \
		p5-Parse-Yapp>=0:${PORTSDIR}/devel/p5-Parse-Yapp \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Graph::Reader.3 \
		Graph::Reader::Dot.3 \
		Graph::Reader::HTK.3 \
		Graph::Reader::XML.3 \
		Graph::Writer.3 \
		Graph::Writer::Dot.3 \
		Graph::Writer::HTK.3 \
		Graph::Writer::VCG.3 \
		Graph::Writer::XML.3 \
		Graph::Writer::daVinci.3

post-patch:
	@${REINPLACE_CMD} -e 's|Graph-ReadWrite|Graph::ReadWrite|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
