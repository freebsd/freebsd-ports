# Ports collection makefile for:  pear-XML_Util
# Date created:			  03 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_Util
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR XML utility class

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	XML
FILES=		Util.php
EXAMPLES=	example.php
DOCS=		blank.html classtrees_XML_Util.html elementindex.html \
		elementindex_XML_Util.html errors.html index.html li_XML_Util.html \
		packages.html todolist.html media/banner.css media/stylesheet.css \
		media/images/blank.png media/images/Class.png \
		media/images/class_folder.png media/images/Constant.png \
		media/images/Constructor.png media/images/Destructor.png \
		media/images/file.png media/images/folder.png media/images/Function.png \
		media/images/function_folder.png media/images/Global.png \
		media/images/I.png media/images/Index.png media/images/L.png \
		media/images/Lminus.png media/images/Lplus.png media/images/Method.png \
		media/images/next_button.png media/images/next_button_disabled.png \
		media/images/package.png media/images/package_folder.png \
		media/images/T.png media/images/Page.png media/images/previous_button.png \
		media/images/previous_button_disabled.png media/images/PrivateClass.png \
		media/images/PrivateMethod.png media/images/PrivateVariable.png \
		media/images/Tminus.png media/images/Tplus.png media/images/tutorial.png \
		media/images/tutorial_folder.png media/images/up_button.png \
		media/images/Variable.png XML_Util/XML_Util.html \
		XML_Util/_Util_XML_XML_Util_php.html
_DOCSDIR=	apidoc

do-install-tests-msg: .USE
	@${ECHO_MSG} "     (These tests require PHPUnit - see"
	@${ECHO_MSG} "     <http://pear.php.net/package-info.php?package=PHPUnit>;;)."

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
