# Ports collection makefile for:  pear-HTML_TreeMenu
# Date created:			  25 September 2004
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTML_TreeMenu
PORTVERSION=	1.2.0
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	Provides an API to create a HTML tree

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML
FILES=		TreeMenu.php
DATA=		TreeMenu.js images/branch.gif images/branchbottom.gif \
		images/branchtop.gif images/folder.gif images/folder-expanded.gif \
		images/line.gif images/linebottom.gif images/minus.gif \
		images/minusbottom.gif images/minustop.gif images/plus.gif \
		images/plusbottom.gif images/plustop.gif imagesAlt/branch.gif \
		imagesAlt/branchbottom.gif imagesAlt/branchtop.gif imagesAlt/folder.gif \
		imagesAlt/folder-expanded.gif imagesAlt/line.gif \
		imagesAlt/linebottom.gif imagesAlt/minus.gif imagesAlt/minusbottom.gif \
		imagesAlt/minustop.gif imagesAlt/plus.gif imagesAlt/plusbottom.gif \
		imagesAlt/plustop.gif imagesAlt2/branch.gif imagesAlt2/branchbottom.gif \
		imagesAlt2/branchtop.gif imagesAlt2/folder.gif \
		imagesAlt2/folder-expanded.gif imagesAlt2/line.gif \
		imagesAlt2/linebottom.gif imagesAlt2/minus.gif \
		imagesAlt2/minusbottom.gif imagesAlt2/minustop.gif imagesAlt2/plus.gif \
		imagesAlt2/plusbottom.gif imagesAlt2/plustop.gif
DOCS=		HTML_TreeMenu.doc HTML_TreeMenu.pdf example.php map_fs.php
_DATADIR=	.

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
