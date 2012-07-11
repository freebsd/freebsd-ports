# Ports collection makefile for:  pear-HTML_QuickForm2
# Date created:			  17 May 2007
# Whom:				  Gerrit Beine (<gerrit.beine@gmx.de>)
#
# $FreeBSD$
#

PORTNAME=	HTML_QuickForm2
PORTVERSION=	0.4.0
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP5 rewrite of the HTML_QuickForm package

BUILD_DEPENDS=	${PEARDIR}/HTML/Common2.php:${PORTSDIR}/devel/pear-HTML_Common2
RUN_DEPENDS:=	${BUILD_DEPENDS}

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

#CATEGORY=	HTML
FILES=		HTML/QuickForm2/Container/Fieldset.php \
		HTML/QuickForm2/Container/Group.php \
		HTML/QuickForm2/Controller/Action/Back.php \
		HTML/QuickForm2/Controller/Action/Direct.php \
		HTML/QuickForm2/Controller/Action/Display.php \
		HTML/QuickForm2/Controller/Action/Jump.php \
		HTML/QuickForm2/Controller/Action/Next.php \
		HTML/QuickForm2/Controller/Action/Submit.php \
		HTML/QuickForm2/Controller/Action.php \
		HTML/QuickForm2/Controller/DefaultAction.php \
		HTML/QuickForm2/Controller/Page.php \
		HTML/QuickForm2/Controller/SessionContainer.php \
		HTML/QuickForm2/DataSource/Array.php \
		HTML/QuickForm2/DataSource/Session.php \
		HTML/QuickForm2/DataSource/Submit.php \
		HTML/QuickForm2/DataSource/SuperGlobal.php \
		HTML/QuickForm2/Element/Button.php \
		HTML/QuickForm2/Element/Input.php \
		HTML/QuickForm2/Element/InputButton.php \
		HTML/QuickForm2/Element/InputCheckable.php \
		HTML/QuickForm2/Element/InputCheckbox.php \
		HTML/QuickForm2/Element/InputFile.php \
		HTML/QuickForm2/Element/InputHidden.php \
		HTML/QuickForm2/Element/InputImage.php \
		HTML/QuickForm2/Element/InputPassword.php \
		HTML/QuickForm2/Element/InputRadio.php \
		HTML/QuickForm2/Element/InputReset.php \
		HTML/QuickForm2/Element/InputSubmit.php \
		HTML/QuickForm2/Element/InputText.php \
		HTML/QuickForm2/Element/Select.php \
		HTML/QuickForm2/Element/Textarea.php \
		HTML/QuickForm2/Renderer/Array.php \
		HTML/QuickForm2/Renderer/Default.php \
		HTML/QuickForm2/Renderer/Plugin.php \
		HTML/QuickForm2/Renderer/Proxy.php \
		HTML/QuickForm2/Rule/Callback.php \
		HTML/QuickForm2/Rule/Compare.php \
		HTML/QuickForm2/Rule/Each.php \
		HTML/QuickForm2/Rule/Empty.php \
		HTML/QuickForm2/Rule/Length.php \
		HTML/QuickForm2/Rule/MaxFileSize.php \
		HTML/QuickForm2/Rule/MimeType.php \
		HTML/QuickForm2/Rule/Nonempty.php \
		HTML/QuickForm2/Rule/Regex.php \
		HTML/QuickForm2/Rule/Required.php \
		HTML/QuickForm2/Container.php \
		HTML/QuickForm2/Controller.php \
		HTML/QuickForm2/DataSource.php \
		HTML/QuickForm2/Element.php \
		HTML/QuickForm2/Exception.php \
		HTML/QuickForm2/Factory.php \
		HTML/QuickForm2/Loader.php \
		HTML/QuickForm2/Node.php \
		HTML/QuickForm2/Renderer.php \
		HTML/QuickForm2/Rule.php \
		HTML/QuickForm2.php
EXAMPLES=	basic-elements.php \
		dualselect.php \
		builtin-rules.php \
		default-renderer.php \
		controller/empty.gif \
		controller/simple.php \
		controller/tabbed.php \
		controller/wizard.php
DATA=		quickform.css
TESTS=		QuickForm2/Container/AllTests.php \
		QuickForm2/Container/FieldsetTest.php \
		QuickForm2/Container/GroupTest.php \
		QuickForm2/DataSource/AllTests.php \
		QuickForm2/DataSource/ArrayTest.php \
		QuickForm2/DataSource/SuperGlobalTest.php \
		QuickForm2/Element/AllTests.php \
		QuickForm2/Element/ButtonTest.php \
		QuickForm2/Element/InputButtonTest.php \
		QuickForm2/Element/InputCheckableTest.php \
		QuickForm2/Element/InputCheckboxTest.php \
		QuickForm2/Element/InputFileTest.php \
		QuickForm2/Element/InputHiddenTest.php \
		QuickForm2/Element/InputImageTest.php \
		QuickForm2/Element/InputPasswordTest.php \
		QuickForm2/Element/InputResetTest.php \
		QuickForm2/Element/InputSubmitTest.php \
		QuickForm2/Element/InputTest.php \
		QuickForm2/Element/SelectTest.php \
		QuickForm2/Element/TextareaTest.php \
		QuickForm2/_files/1024-bytes.upload \
		QuickForm2/_files/FakeRule.php \
		QuickForm2/_files/FakeElement.php \
		QuickForm2/_files/InvalidFile.php \
		QuickForm2/AllTests.php \
		QuickForm2/ContainerOverloadTest.php \
		QuickForm2/ControllerTest.php \
		QuickForm2/ContainerTest.php \
		QuickForm2/ElementTest.php \
		QuickForm2/FactoryTest.php \
		QuickForm2/NodeTest.php \
		QuickForm2/RendererTest.php \
		QuickForm2/RuleTest.php \
		AllTests.php \
		QuickForm2Test.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
