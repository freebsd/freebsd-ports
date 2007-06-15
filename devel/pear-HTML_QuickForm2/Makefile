# Ports collection makefile for:  pear-HTML_QuickForm2
# Date created:			  17 May 2007
# Whom:				  Gerrit Beine (<gerrit.beine@gmx.de>)
#
# $FreeBSD$
#

PORTNAME=	HTML_QuickForm2
PORTVERSION=	0.1.0
CATEGORIES=	devel www pear

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	PHP5 rewrite of the HTML_QuickForm package

BUILD_DEPENDS=	${PEARDIR}/HTML/Common2.php:${PORTSDIR}/devel/pear-HTML_Common2
RUN_DEPENDS=	${BUILD_DEPENDS}

DEFAULT_PHP_VER=5
IGNORE_WITH_PHP=4

CATEGORY=	HTML
FILES=		QuickForm2/Container/Fieldset.php \
		QuickForm2/DataSource/Array.php \
		QuickForm2/DataSource/Submit.php \
		QuickForm2/DataSource/SuperGlobal.php \
		QuickForm2/Element/Button.php \
		QuickForm2/Element/Input.php \
		QuickForm2/Element/InputButton.php \
		QuickForm2/Element/InputCheckable.php \
		QuickForm2/Element/InputCheckbox.php \
		QuickForm2/Element/InputFile.php \
		QuickForm2/Element/InputHidden.php \
		QuickForm2/Element/InputImage.php \
		QuickForm2/Element/InputPassword.php \
		QuickForm2/Element/InputRadio.php \
		QuickForm2/Element/InputReset.php \
		QuickForm2/Element/InputSubmit.php \
		QuickForm2/Element/InputText.php \
		QuickForm2/Element/Select.php \
		QuickForm2/Element/Textarea.php \
		QuickForm2/Container.php \
		QuickForm2/DataSource.php \
		QuickForm2/Element.php \
		QuickForm2/Exception.php \
		QuickForm2/Factory.php \
		QuickForm2/Node.php \
		QuickForm2.php
EXAMPLES=	basic-elements.php
TESTS=		QuickForm2/Container/AllTests.php \
		QuickForm2/Container/FieldsetTest.php \
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
		QuickForm2/_files/FakeElement.php \
		QuickForm2/_files/InvalidFile.php \
		QuickForm2/AllTests.php \
		QuickForm2/ContainerTest.php \
		QuickForm2/ElementTest.php \
		QuickForm2/FactoryTest.php \
		QuickForm2/NodeTest.php \
		AllTests.php \
		QuickForm2Test.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
