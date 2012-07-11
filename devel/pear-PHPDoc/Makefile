# Ports collection makefile for:  pear-PHPDoc
# Date created:			  22 July 2005
# Whom:				  Gerrit Beine (<gerrit@beine-computer.de>)
#
# $FreeBSD$
#

PORTNAME=	PHPDoc
PORTVERSION=	0.1.0
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to generate documentation from the source

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS:=	${BUILD_DEPENDS}

CATEGORY=	PHPDoc
FILES=		accessor/PhpdocAccessor.php \
		accessor/PhpdocClassAccessor.php \
		accessor/PhpdocDocumentAccessor.php \
		accessor/PhpdocIndexAccessor.php \
		accessor/PhpdocModuleAccessor.php \
		accessor/PhpdocWarningAccessor.php \
		analyser/PhpdocAnalyser.php \
		analyser/PhpdocClassAnalyser.php \
		analyser/PhpdocModuleAnalyser.php \
		core/Phpdoc.php \
		core/PhpdocArgvHandler.php \
		core/PhpdocObject.php \
		core/PhpdocSetupHandler.php \
		exceptions/PhpdocError.php \
		filehandler/PhpdocFileHandler.php \
		indexer/PhpdocIndexer.php \
		parser/PhpdocClassParser.php \
		parser/PhpdocConstantParser.php \
		parser/PhpdocFunctionParser.php \
		parser/PhpdocModuleParser.php \
		parser/PhpdocParser.php \
		parser/PhpdocParserCore.php \
		parser/PhpdocParserRegExp.php \
		parser/PhpdocParserTags.php \
		parser/PhpdocUseParser.php \
		parser/PhpdocVariableParser.php \
		redist/IT.php \
		redist/ITX.php \
		renderer/PhpdocRendererObject.php \
		renderer/html/PhpdocHTMLClassRenderer.php \
		renderer/html/PhpdocHTMLDocumentRenderer.php \
		renderer/html/PhpdocHTMLIndexRenderer.php \
		renderer/html/PhpdocHTMLModuleRenderer.php \
		renderer/html/PhpdocHTMLRenderer.php \
		renderer/html/PhpdocHTMLRendererManager.php \
		renderer/html/PhpdocHTMLWarningRenderer.php \
		renderer/html/templates.php \
		warning/PhpdocWarning.php \
		xmlexporter/PhpdocXMLClassExporter.php \
		xmlexporter/PhpdocXMLDocumentExporter.php \
		xmlexporter/PhpdocXMLExporter.php \
		xmlexporter/PhpdocXMLIndexExporter.php \
		xmlexporter/PhpdocXMLModuleExporter.php \
		xmlexporter/PhpdocXMLWarningExporter.php \
		xmlreader/PhpdocXMLReader.php \
		xmlwriter/PhpdocXMLWriter.php \
		prepend.php
_DATADIR=	.
DATA=		renderer/html/default/class.html \
		renderer/html/default/classtree.html \
		renderer/html/default/elementlist.html \
		renderer/html/default/frame_packageelementlist.html \
		renderer/html/default/frame_packagelist.html \
		renderer/html/default/module.html \
		renderer/html/default/modulegroup.html \
		renderer/html/default/packagelist.html \
		renderer/html/default/warnings.html \
		renderer/html/default/xmlfiles.html \
		renderer/html/default/static/empty.html \
		renderer/html/default/static/index.html \
		renderer/html/default/static/phpdoc.css \
		renderer/html/default/static/phpdoc.dtd \
		renderer/html/timmyg/bottom_nav.html \
		renderer/html/timmyg/class.html \
		renderer/html/timmyg/classtree.html \
		renderer/html/timmyg/elementlist.html \
		renderer/html/timmyg/frame_packageelementlist.html \
		renderer/html/timmyg/frame_packagelist.html \
		renderer/html/timmyg/module.html \
		renderer/html/timmyg/modulegroup.html \
		renderer/html/timmyg/packagelist.html \
		renderer/html/timmyg/top_nav.html \
		renderer/html/timmyg/warnings.html \
		renderer/html/timmyg/xmlfiles.html \
		renderer/html/timmyg/static/empty.html \
		renderer/html/timmyg/static/index.html \
		renderer/html/timmyg/static/phpdoc.css \
		renderer/html/timmyg/static/phpdoc.dtd \
		renderer/html/timmyg/static/phpdoc_warnings.html \
		renderer/html/.empty \
		renderer/.empty
SCRIPTFILES=	phpdoc

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"

post-patch:
	@${REINPLACE_CMD} -e "s,@php_dir@,${PEARDIR}," \
		-e "s,@doc_dir@,${DOCSDIR}," \
		-e "s,@data_dir@,${DATADIR}," ${WRKSRC}/phpdoc
	@${MV} ${WRKSRC}/phpdoc ${WRKSRC}/pear-phpdoc
	@${TOUCH} ${WRKSRC}/renderer/html/.empty
	@${TOUCH} ${WRKSRC}/renderer/.empty

.include <bsd.port.post.mk>
