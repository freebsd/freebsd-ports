# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	HTML_Template_Flexy
PORTVERSION=	1.3.12
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	An extremely powerful Tokenizer driven Template engine

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

LATEST_LINK=	pear-HTML_Template_Flexy
OPTIONS_DEFINE=	PEAR_HTML_JAVASCRIPT PEAR_FILE_GETTEXT PEAR_TRANSLATION2
PEAR_HTML_JAVASCRIPT_DESC=	PEAR::HTML_Javascript support
PEAR_FILE_GETTEXT_DESC=	PEAR::File_Gettext support
PEAR_TRANSLATION2_DESC=	PEAR::Translation2 support

PEAR_AUTOINSTALL=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPEAR_HTML_JAVASCRIPT}
RUN_DEPENDS+=	${PEARDIR}/HTML/Javascript.php:${PORTSDIR}/devel/pear-HTML_Javascript
.endif

.if ${PORT_OPTIONS:MPEAR_FILE_GETTEXT}
RUN_DEPENDS+=	${PEARDIR}/File/Gettext.php:${PORTSDIR}/sysutils/pear-File_Gettext
.endif

.if ${PORT_OPTIONS:MPEAR_TRANSLATION2}
RUN_DEPENDS+=	${PEARDIR}/Translation2.php:${PORTSDIR}/sysutils/pear-Translation2
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.mk>
