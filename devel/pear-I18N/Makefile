# Ports collection makefile for:  pear-I18N
# Date created:			  30 November 2002
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	I18N
PORTVERSION=	0.8.6
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR internationalization package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	I18N
FILES=		Common/af.php Common/da_DK.php Common/de.php \
		Common/de_AT.php Common/de_DE.php Common/en.php \
		Common/en_GB.php Common/en_UK.php Common/en_US.php \
		Common/en_ZA.php Common/es.php Common/es_ES.php \
		Common/fr.php Common/fr_FR.php Common/hu.php \
		Common/it.php Common/it_IT.php Common/nl.php \
		Common/nl_NL.php Common/pl.php Common/pt.php \
		Common/ru.php Common/sl.php Common.php Country.php \
		Currency.php DateTime.php Format.php Language.php \
		Negotiator.php Number.php Messages/Common.php \
		Messages/File.php Messages/Translate.php \
		Messages/determineLanguage.inc.php
EXAMPLES=	I18N_Currency.php I18N_DateTime.php I18N_Message.php		\
		I18N_Message_Translate.php I18N_Message_Translate.tpl		\
		I18N_Negotiator.php I18N_Number.php
_EXAMPLESDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
