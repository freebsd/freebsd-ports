# Ports collection makefile for:  pear-HTML_QuickForm
# Date created:			  30 March 2004
# Whom:				  Gerrit Beine (<gerrit@beine-computer.de>)
#
# $FreeBSD$
#

PORTNAME=	HTML_QuickForm
PORTVERSION=	3.2.11
CATEGORIES=	devel www pear

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Provide methods for creating, validating and processing HTML forms

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML
FILES=		QuickForm.php \
		QuickForm/advcheckbox.php QuickForm/autocomplete.php QuickForm/button.php \
		QuickForm/checkbox.php QuickForm/date.php QuickForm/element.php \
		QuickForm/file.php QuickForm/group.php QuickForm/header.php \
		QuickForm/hidden.php QuickForm/hiddenselect.php QuickForm/hierselect.php \
		QuickForm/html.php QuickForm/image.php QuickForm/input.php \
		QuickForm/link.php QuickForm/password.php QuickForm/radio.php \
		QuickForm/reset.php QuickForm/select.php QuickForm/static.php \
		QuickForm/submit.php QuickForm/text.php QuickForm/textarea.php \
		QuickForm/xbutton.php \
		QuickForm/Renderer.php QuickForm/Rule.php QuickForm/RuleRegistry.php \
		QuickForm/Renderer/Array.php QuickForm/Renderer/ArraySmarty.php \
		QuickForm/Renderer/Default.php \
		QuickForm/Renderer/ITDynamic.php QuickForm/Renderer/ITStatic.php \
		QuickForm/Renderer/Object.php \
		QuickForm/Renderer/ObjectFlexy.php QuickForm/Renderer/QuickHtml.php \
		QuickForm/Rule/Callback.php QuickForm/Rule/Compare.php QuickForm/Rule/Email.php \
		QuickForm/Rule/Range.php QuickForm/Rule/Regex.php QuickForm/Rule/Required.php
DOCS=		elements.php filters.php formrule.php groups.php rules-builtin.php rules-custom.php \
		renderers/FlexyDynamic_example.php renderers/FlexyStatic_example.php \
		renderers/ITDynamic_example.php renderers/ITDynamic_example2.php \
		renderers/ITStatic_example.php renderers/QuickHtml_example.php \
		renderers/SmartyDynamic_example.php renderers/SmartyStatic_example.php \
		renderers/multiple-labels.php renderers/templates/it-dynamic-2.html \
		renderers/templates/it-dynamic.html renderers/templates/it-static.html \
		renderers/templates/smarty-dynamic-fancygroup.tpl \
		renderers/templates/smarty-dynamic-green.tpl renderers/templates/smarty-dynamic.tpl \
		renderers/templates/smarty-static.tpl renderers/templates/html.html \
		renderers/templates/flexy-dynamic.html renderers/templates/flexy-static.html \
		renderers/templates/label.html renderers/templates/styles/green.html \
		renderers/templates/styles/fancygroup.html

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
