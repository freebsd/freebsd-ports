# Created by: ijliao
# $FreeBSD$

PORTNAME=	autodia
PORTVERSION=	2.14
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEEJAY
DISTNAME=	Autodia-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automatic Dia XML - from Source Code and Data

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-HTML-Mason>=0:${PORTSDIR}/www/p5-HTML-Mason
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	GRAPHVIZ SPRINGGRAPH VCG DOCS
OPTIONS_DEFAULT=	GRAPHVIZ SPRINGGRAPH VCG
SPRINGGRAPH_DESC=	SpringGraph support
VCG_DESC=		VCG support

USES=		perl5
USE_PERL5=	configure

MAN1=		autodia.pl.1
MAN3=		Autodia.3 autodia.3 \
		Autodia::Diagram.3 \
		Autodia::Diagram::Class.3 \
		Autodia::Diagram::Component.3 \
		Autodia::Handler.3 \
		Autodia::Handler::ASP.3 \
		Autodia::Handler::CSharp.3 \
		Autodia::Handler::Cpp.3 \
		Autodia::Handler::DBI.3 \
		Autodia::Handler::DBI_SQLT.3 \
		Autodia::Handler::Mason.3 \
		Autodia::Handler::PHP.3 \
		Autodia::Handler::Perl.3 \
		Autodia::Handler::SQL.3 \
		Autodia::Handler::Torque.3 \
		Autodia::Handler::dia.3 \
		Autodia::Handler::umbrello.3
PORTDOCS=	CHANGES CREDITS DEVELOP FAQ INSTALL MANIFEST README TODO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGRAPHVIZ}
RUN_DEPENDS+=	p5-GraphViz>=0:${PORTSDIR}/graphics/p5-GraphViz
.endif

.if ${PORT_OPTIONS:MSPRINGGRAPH}
RUN_DEPENDS+=	p5-SpringGraph>=0:${PORTSDIR}/graphics/p5-SpringGraph
.endif

.if ${PORT_OPTIONS:MVCG}
RUN_DEPENDS+=	p5-VCG>=0:${PORTSDIR}/graphics/p5-VCG
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^#!/s|/.*perl|${PERL}|' ${WRKSRC}/autodia.pl

pre-configure:
	@${FIND} ${WRKSRC} -name "*.orig" -delete

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
