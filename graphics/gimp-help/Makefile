# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gimp-help
PORTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	graphics
PKGNAMESUFFIX=	-html

MAINTAINER=	liangtai.s16@gmail.com
COMMENT=	Meta port for the GIMP User Manual

LICENSE=	GFDL

USES=		metaport

LANG_ALL_HTML=	ca da de el en en_GB es fr it ja ko nl nn \
		pt_BR ru sl sv zh_CN

de_PORT=	german/gimp-help
fr_PORT=	french/gimp-help
ja_PORT=	japanese/gimp-help
ko_PORT=	korean/gimp-help
pt_BR_PORT=	portuguese/gimp-help-pt_BR
ru_PORT=	russian/gimp-help
zh_CN_PORT=	chinese/gimp-help-zh_CN

# you can find more in ${PORTSDIR}/misc/kde4-l10n/files/kde4-lang-names
ca_NAME=	Catalan
da_NAME=	Danish
de_NAME=	German
el_NAME=	Greek
en_NAME=	English
en_GB_NAME=	British English
es_NAME=	Spanish
fr_NAME=	French
it_NAME=	Italian
ja_NAME=	Japanese
ko_NAME=	Korean
nl_NAME=	Dutch
nn_NAME=	Norwegian Nynorsk
pt_BR_NAME=	Brazilian Portuguese
ru_NAME=	Russian
sl_NAME=	Slovenian
sv_NAME=	Swedish
zh_CN_NAME=	Chinese Simplified

OPTIONS_DEFINE=	ALL ${LANG_ALL_HTML:tu}
OPTIONS_DEFAULT=	ALL
ALL_DESC=	All translations

.for lang in ${LANG_ALL_HTML}
${lang}_DETECT?=	${LOCALBASE}/share/gimp/help/${lang}/index.html
${lang}_PORT?=		misc/gimp-help-${lang}
${lang}_NAME?=		${lang}
${lang:tu}_DESC=		${${lang}_NAME}
${lang:tu}_RUN_DEPENDS=	${${lang}_DETECT}:${${lang}_PORT}
ALL_RUN_DEPENDS+=	${${lang}_DETECT}:${${lang}_PORT}
.endfor

.include <bsd.port.mk>
