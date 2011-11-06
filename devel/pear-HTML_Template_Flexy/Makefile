# Ports collection makefile for:  pear-HTML_Template_Flexy
# Date created:			  04 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Template_Flexy
PORTVERSION=	1.3.12
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An extremely powerful Tokenizer driven Template engine

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

LATEST_LINK=	pear-HTML_Template_Flexy
OPTIONS=	PEAR_HTML_JAVASCRIPT "PEAR::HTML_Javascript support" off \
		PEAR_FILE_GETTEXT "PEAR::File_Gettext support" off \
		PEAR_TRANSLATION2 "PEAR::Translation2 support" off

PEAR_AUTOINSTALL=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_HTML_JAVASCRIPT)
RUN_DEPENDS+=	${PEARDIR}/HTML/Javascript.php:${PORTSDIR}/devel/pear-HTML_Javascript
.endif

.if defined(WITH_PEAR_FILE_GETTEXT)
RUN_DEPENDS+=	${PEARDIR}/File/Gettext.php:${PORTSDIR}/sysutils/pear-File_Gettext
.endif

.if defined(WITH_PEAR_TRANSLATION2)
RUN_DEPENDS+=	${PEARDIR}/Translation2.php:${PORTSDIR}/sysutils/pear-Translation2
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
