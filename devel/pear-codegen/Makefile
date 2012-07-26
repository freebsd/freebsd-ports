# Ports collection makefile for:  pear-CodeGen
# Date created:			  27 Jan 2007
# Whom:				  Ditesh Shashikant Gathani <ditesh@gathani.org>
#
# $FreeBSD$
#

PORTNAME=	codegen
PORTVERSION=	1.0.7
CATEGORIES=	devel pear
DISTNAME=	CodeGen-${PORTVERSION}

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Tool to create code generators that operate on XML descriptions

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

FILES=		CodeGen/XmlParser.php CodeGen/Release.php CodeGen/Maintainer.php \
		CodeGen/License.php CodeGen/Extension.php CodeGen/ExtensionParser.php \
		CodeGen/Element.php CodeGen/Command.php CodeGen/Tools/Tokenizer.php \
		CodeGen/Tools/Platform.php CodeGen/Tools/Outbuf.php CodeGen/Tools/IndentC.php \
		CodeGen/Tools/Indent.php CodeGen/Tools/Getopt.php \
		CodeGen/Tools/Group.php CodeGen/Tools/Code.php \
		CodeGen/Tools/FileReplacer.php CodeGen/License/GPL.php CodeGen/License/BSD.php \
		CodeGen/License/GPL2.php CodeGen/License/GPL3.php \
		CodeGen/License/LGPL21.php CodeGen/License/LGPL3.php \
		CodeGen/License/LGPL.php CodeGen/License/PHP.php CodeGen/Dependency/Lib.php \
		CodeGen/Dependency/Header.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
