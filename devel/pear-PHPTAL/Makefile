# Ports collection makefile for:  pear-PHPTAL
# Date created:			  2010-10-4
# Whom:				  Tom Judge <tom@tomjudge.com>
#
# $FreeBSD$

PORTNAME=	PHPTAL
PORTVERSION=	1.2.2
CATEGORIES=	devel www pear
MASTER_SITES=	http://phptal.org/files/

MAINTAINER=	tom@tomjudge.com
COMMENT=	PEAR PHPTAL is a XML/XHTML template library for PHP

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

OPTIONS=	GETTEXT "Enable GetText Support" off \
		SIMPLEXML "Enable SimpleXML Support" off \
		JSON "Enable JSON Support" off

USE_PHP=	ctype hash

.if defined(WITH_GETTEXT)
USE_PHP+=	gettext
.endif

.if defined(WITH_SIMPLEXML)
USE_PHP+=	simplexml
.endif

.if defined(WITH_JSON)
USE_PHP+=	json
.endif

PEAR_DIST_SUFX=	.tar.gz
FILES=		PHPTAL/ConfigurationException.php PHPTAL/Context.php \
		PHPTAL/Dom/Attr.php PHPTAL/Dom/CDATASection.php \
		PHPTAL/Dom/Comment.php PHPTAL/Dom/Defs.php \
		PHPTAL/Dom/DocumentBuilder.php PHPTAL/Dom/DocumentType.php \
		PHPTAL/Dom/Element.php PHPTAL/Dom/Node.php \
		PHPTAL/Dom/PHPTALDocumentBuilder.php \
		PHPTAL/Dom/ProcessingInstruction.php PHPTAL/Dom/SaxXmlParser.php \
		PHPTAL/Dom/Text.php PHPTAL/Dom/XmlDeclaration.php \
		PHPTAL/Dom/XmlnsState.php PHPTAL/Exception.php \
		PHPTAL/ExceptionHandler.php PHPTAL/FileSource.php \
		PHPTAL/FileSourceResolver.php PHPTAL/Filter.php \
		PHPTAL/GetTextTranslator.php \
		PHPTAL/InvalidVariableNameException.php \
		PHPTAL/IOException.php PHPTAL/MacroMissingException.php \
		PHPTAL/Namespace/Builtin.php PHPTAL/Namespace/I18N.php \
		PHPTAL/Namespace/METAL.php PHPTAL/Namespace/PHPTAL.php \
		PHPTAL/Namespace/TAL.php PHPTAL/Namespace.php \
		PHPTAL/NamespaceAttribute.php PHPTAL/NamespaceAttributeContent.php \
		PHPTAL/NamespaceAttributeReplace.php \
		PHPTAL/NamespaceAttributeSurround.php \
		PHPTAL/ParserException.php \
		PHPTAL/Php/Attribute/I18N/Attributes.php \
		PHPTAL/Php/Attribute/I18N/Data.php \
		PHPTAL/Php/Attribute/I18N/Domain.php \
		PHPTAL/Php/Attribute/I18N/Name.php \
		PHPTAL/Php/Attribute/I18N/Source.php \
		PHPTAL/Php/Attribute/I18N/Target.php \
		PHPTAL/Php/Attribute/I18N/Translate.php \
		PHPTAL/Php/Attribute/METAL/DefineMacro.php \
		PHPTAL/Php/Attribute/METAL/DefineSlot.php \
		PHPTAL/Php/Attribute/METAL/FillSlot.php \
		PHPTAL/Php/Attribute/METAL/UseMacro.php \
		PHPTAL/Php/Attribute/PHPTAL/Cache.php \
		PHPTAL/Php/Attribute/PHPTAL/Debug.php \
		PHPTAL/Php/Attribute/PHPTAL/Id.php \
		PHPTAL/Php/Attribute/PHPTAL/Tales.php \
		PHPTAL/Php/Attribute/TAL/Attributes.php \
		PHPTAL/Php/Attribute/TAL/Comment.php \
		PHPTAL/Php/Attribute/TAL/Condition.php \
		PHPTAL/Php/Attribute/TAL/Content.php \
		PHPTAL/Php/Attribute/TAL/Define.php \
		PHPTAL/Php/Attribute/TAL/OmitTag.php \
		PHPTAL/Php/Attribute/TAL/OnError.php \
		PHPTAL/Php/Attribute/TAL/Repeat.php \
		PHPTAL/Php/Attribute/TAL/Replace.php \
		PHPTAL/Php/Attribute.php PHPTAL/Php/CodeWriter.php \
		PHPTAL/Php/State.php PHPTAL/Php/TalesChainExecutor.php \
		PHPTAL/Php/TalesChainReader.php PHPTAL/Php/TalesInternal.php \
		PHPTAL/Php/Transformer.php PHPTAL/PreFilter/Compress.php \
		PHPTAL/PreFilter/Normalize.php PHPTAL/PreFilter/StripComments.php \
		PHPTAL/PreFilter.php PHPTAL/RepeatController.php \
		PHPTAL/RepeatControllerGroups.php PHPTAL/Source.php \
		PHPTAL/SourceResolver.php PHPTAL/StringSource.php \
		PHPTAL/Tales.php PHPTAL/TalesRegistry.php \
		PHPTAL/TemplateException.php PHPTAL/Tokenizer.php \
		PHPTAL/TranslationService.php PHPTAL/Trigger.php \
		PHPTAL/UnknownModifierException.php \
		PHPTAL/VariableNotFoundException.php \
		PHPTAL.php

TESTS=		ArrayOverloadTest.php AttributesInterpolationTest.php \
		AutoloadTest1.php AutoloadTest2.php BlockTest.php \
		CodeCacheTest.php CommentFilterTest.php CommentTest.php \
		CompressTest.php config.php ContentEncodingTest.php \
		ContentInterpolationTest.php DoctypeTest.php DomTest.php \
		EchoExecuteTest.php EscapeCDATATest.php EscapeHTMLTest.php \
		gen-mos.sh GetTextTest.php HTML5ModeTest.php HTMLGeneratorTest.php \
		I18NAttributesTest.php I18NDummyTranslator.php I18NNameTest.php \
		I18NTranslateTest.php input/array-overload.01.html \
		input/code-cache-01.html input/comment-filter-01.html \
		input/content-encoding.xml input/doctype.01.html \
		input/doctype.02.html input/doctype.02.user.html \
		input/doctype.03.html input/doctype.03.sub1.html \
		input/doctype.03.sub2.html input/doctype.04.html \
		input/error-01.html input/error-02.html input/error-02.macro.html \
		input/error-03.html input/error-03.macro.html input/error-04.html \
		input/error-05.html input/error-06.html input/error-07.html \
		input/error-08.html input/error-09.html input/error-10.html \
		input/error-11.html input/error-12.html input/error-13.html \
		input/escape.html input/gettext.01.html input/gettext.02.html \
		input/gettext.03.html input/gettext.04.html input/gettext.05.html \
		input/gettext.06.html input/gettext.07.html \
		input/i18n-attributes-01.html input/i18n-attributes-02.html \
		input/i18n-attributes-03.html input/i18n-attributes-04.html \
		input/i18n-attributes-05.html input/i18n-name-01.html \
		input/i18n-name-02.html input/i18n-name-03.html \
		input/i18n-name-04.html input/i18n-name-05.html \
		input/i18n-name-06.html input/i18n-translate-01.html \
		input/i18n-translate-02.html input/metal-macro.01.html \
		input/metal-macro.02.html input/metal-macro.03.html \
		input/metal-macro.04.html input/metal-macro.04.main.html \
		input/metal-macro.05.html input/metal-macro.06.html \
		input/metal-macro.07.html input/metal-macro.08.html \
		input/metal-macro.09.html input/metal-macro.10.html \
		input/metal-macro.11.html input/metal-slot.01.html \
		input/metal-slot.02.html input/metal-slot.03.html \
		input/metal-slot.04.html input/metal-slot.05.html \
		input/multiuse.01.html input/multiuse.02.html \
		input/namespaces.01.html input/namespaces.02.html \
		input/namespaces.03.html input/old-03.html input/old-06.html \
		input/old-08-mcr.html input/old-08.html input/old-11.html \
		input/old-12.html input/old-13.html input/old-15.html \
		input/old-16.html input/old-17.html input/old-19.html \
		input/old-20.html input/old-21.html input/old-23.html \
		input/old-29-mcr.html input/old-29.html input/old-30.html \
		input/old-31.html input/old-32.html input/overloading-01.html \
		input/parser.01.xml input/parser.02.xml input/parser.03.xml \
		input/php-mode.01.xml input/php-mode.02.xml input/php.html \
		input/phptal.01.html input/phptal.02.html input/phptal.03.html \
		input/phptal.04.html input/phptal.05.html input/phptal.06.html \
		input/phptal.id.01.html input/postfilter.01.html \
		input/prefilter.01.html input/prefilter.02.html \
		input/prefilter.02.macro.html input/prefilter.03.html \
		input/tal-attributes.01.html input/tal-attributes.02.html \
		input/tal-attributes.03.html input/tal-attributes.04.html \
		input/tal-attributes.05.html input/tal-attributes.06.html \
		input/tal-attributes.07.html input/tal-attributes.08.html \
		input/tal-attributes.09.html input/tal-attributes.10.html \
		input/tal-comment.01.html input/tal-comment.02.html \
		input/tal-condition.01.html input/tal-condition.02.html \
		input/tal-condition.03.html input/tal-condition.04.html \
		input/tal-content.01.html input/tal-content.02.html \
		input/tal-content.03.html input/tal-content.04.html \
		input/tal-content.05.html input/tal-content.06.html \
		input/tal-define.01.html input/tal-define.02.html \
		input/tal-define.03.html input/tal-define.04.html \
		input/tal-define.05.html input/tal-define.06.html \
		input/tal-define.07.html input/tal-define.08.html \
		input/tal-define.09.html input/tal-define.10.html \
		input/tal-define.11.html input/tal-define.12.html \
		input/tal-define.13.html input/tal-define.14.html \
		input/tal-omit-tag.01.html input/tal-omit-tag.02.html \
		input/tal-on-error.01.html input/tal-on-error.02.html \
		input/tal-on-error.03.html input/tal-repeat.01.html \
		input/tal-repeat.02.html input/tal-repeat.03.html \
		input/tal-repeat.04.html input/tal-repeat.05.html \
		input/tal-repeat.06.html input/tal-repeat.07.html \
		input/tal-replace.01.html input/tal-replace.02.html \
		input/tal-replace.03.html input/tal-replace.04.html \
		input/tal-replace.05.html input/tal-replace.06.html \
		input/tal-replace.07.html input/tales-exist-01.html \
		input/tales-exist-02.html input/tales-string-01.html \
		input/tales-string-02.html input/tales-string-03.html \
		input/tales-true.html input/tales.mode.01.xml \
		input/talesphpwithreplace.01.html input/trigger.01.html \
		input/utf8.xml input/xml.01.xml input/xml.02.xml input/xml.03.xml \
		input/xml.04.xml Latin1Test.php locale/en_GB/LC_MESSAGES/test.mo \
		locale/en_GB/LC_MESSAGES/test.php locale/en_GB/LC_MESSAGES/test.po \
		locale/en_GB/LC_MESSAGES/test2.mo locale/en_GB/LC_MESSAGES/test2.po \
		locale/es_ES/LC_MESSAGES/test.mo locale/es_ES/LC_MESSAGES/test.po \
		locale/fr_FR/LC_MESSAGES/test.mo locale/fr_FR/LC_MESSAGES/test.php \
		locale/fr_FR/LC_MESSAGES/test.po locale/fr_FR/LC_MESSAGES/test2.mo \
		locale/fr_FR/LC_MESSAGES/test2.php locale/fr_FR/LC_MESSAGES/test2.po \
		MetalMacroTest.php MetalSlotTest.php NamespacesTest.php \
		OldPreFilterTest.php OldTest.php output/array-overload.01.html \
		output/comment-filter-01.html output/content-encoding.xml \
		output/doctype.01.html output/doctype.02.html output/doctype.03.html \
		output/doctype.04.html output/escape.html output/gettext.01.html \
		output/gettext.02.html output/gettext.03.html output/gettext.04.html \
		output/gettext.05.html output/gettext.06.html output/gettext.07.html \
		output/i18n-attributes-01.html output/i18n-attributes-02.html \
		output/i18n-attributes-03.html output/i18n-attributes-04.html \
		output/i18n-attributes-05.html output/i18n-name-02.html \
		output/i18n-name-03.html output/i18n-name-04.html \
		output/i18n-name-05.html output/i18n-name-06.html \
		output/i18n-translate-01.html output/i18n-translate-02.html \
		output/metal-macro.01.html output/metal-macro.02.html \
		output/metal-macro.03.html output/metal-macro.04.html \
		output/metal-macro.05.html output/metal-macro.06.html \
		output/metal-macro.07.html output/metal-slot.01.html \
		output/metal-slot.02.html output/metal-slot.03.html \
		output/metal-slot.04.html output/namespaces.01.html \
		output/namespaces.02.html output/namespaces.03.html \
		output/old-03.html output/old-06.html output/old-08.html \
		output/old-11.html output/old-12.html output/old-13.html \
		output/old-15.html output/old-16.html output/old-17.html \
		output/old-19.html output/old-20.html output/old-21.html \
		output/old-23.html output/old-29.html output/old-30.html \
		output/old-31.html output/old-32.html output/overloading-01.html \
		output/php-mode.01.xml output/php-mode.02.xml output/php.html \
		output/phptal.02.html output/phptal.04.html output/phptal.06.html \
		output/phptal.id.01.html output/postfilter.01.html \
		output/prefilter.01.html output/prefilter.02.html \
		output/tal-attributes.01.html output/tal-attributes.02.html \
		output/tal-attributes.03.html output/tal-attributes.04.html \
		output/tal-attributes.05.html output/tal-attributes.06.html \
		output/tal-attributes.07.html output/tal-attributes.08.html \
		output/tal-attributes.09.html output/tal-attributes.10.html \
		output/tal-comment.01.html output/tal-comment.02.html \
		output/tal-condition.01.html output/tal-condition.02.html \
		output/tal-condition.03.html output/tal-content.01.html \
		output/tal-content.02.html output/tal-content.03.html \
		output/tal-content.04.html output/tal-content.05.html \
		output/tal-content.06.html output/tal-define.01.html \
		output/tal-define.02.html output/tal-define.03.html \
		output/tal-define.04.html output/tal-define.05.html \
		output/tal-define.06.html output/tal-define.07.html \
		output/tal-define.08.html output/tal-define.09.html \
		output/tal-define.10.html output/tal-define.11.html \
		output/tal-define.12.html output/tal-define.13.html \
		output/tal-define.14.html output/tal-omit-tag.01.html \
		output/tal-omit-tag.02.html output/tal-on-error.01.html \
		output/tal-on-error.02.html output/tal-on-error.03.html \
		output/tal-repeat.01.html output/tal-repeat.02.html \
		output/tal-repeat.03.html output/tal-repeat.04.html \
		output/tal-repeat.05.html output/tal-repeat.06.html \
		output/tal-repeat.07.html output/tal-replace.01.html \
		output/tal-replace.02.html output/tal-replace.03.html \
		output/tal-replace.04.html output/tal-replace.05.html \
		output/tal-replace.06.html output/tal-replace.07.html \
		output/tales-exist-01.html output/tales-exist-02.html \
		output/tales-string-01.html output/tales-string-02.html \
		output/tales-string-03.html output/tales-true.html \
		output/talesphpwithreplace.01.html output/trigger.01.html \
		output/xml.03.xml OverloadingTest.php ParserTest.php \
		PhpModeTest.php PhptalCacheTest.php PhptalIdTest.php \
		PhptalPathTest.php PhptalTest.php PhptalUsageTest.php \
		PhpTransformerTest.php PostFilterTest.php \
		PreFilterNormalizeTest.php ReadableErrorTest.php \
		run-tests.php SimpleGenerationTest.php TalAttributesTest.php \
		TalCommentTest.php TalConditionTest.php TalContentTest.php \
		TalDefineTest.php TalesClosuresTest.php TalesExistTest.php \
		TalesIssetNullTest.php TalesModeTest.php TalesPhpTest.php \
		TalesPhpWithReplaceTest.php TalesStringTest.php \
		TalesTest.php TalOmitTagTest.php TalOnErrorTest.php \
		TalRepeatTest.php TalReplaceTest.php \
		TemplateRepositoryTest.php TokenizerTest.php TriggerTest.php \
		UTF8Test.php XHTMLModeTest.php

_DOCSDIR=	.
DOCS=		COPYING README

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
