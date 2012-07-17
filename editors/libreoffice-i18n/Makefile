# New ports collection makefile for:	libreoffice-i18n
# Date created:		2012-03-01
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

.include "${.CURDIR}/../libreoffice/Makefile.common"
UNIQUENAME=   ${PORTNAME}${PKGNAMESUFFIX}
PKGNAMESUFFIX=	-i18n
DISTFILES= 	#none
MASTER_SITES=	#none
EXTRACT_ONLY=	#none

COMMENT=	Localized interface for libreoffice

NO_BUILD=	yes

LO_LANG_ALL=	af ar as ast be bg bn bo br brx bs ca_XV ca cs cy da de dgo \
		dz el en_GB en_ZA eo es et eu fa fi fr ga gd gl gu he hi hr \
		hu id is it ja ka kk km kn ko kok ks ku lb lo lt lv mai mk \
		ml mn mni mr my nb ne nl nn nr nso oc om or pa_IN pl pt_BR \
		pt ro ru rw sa_IN sat sd sh si sk sl sq sr ss st sv sw_TZ \
		ta te tg th tn tr ts tt ug uk uz ve vi xh zh_CN zh_TW zu

ar_PORT=	arabic/${PORTNAME}
de_PORT=	german/${PORTNAME}
fr_PORT=	french/${PORTNAME}
he_PORT=	hebrew/${PORTNAME}
hu_PORT=	hungarian/${PORTNAME}
ja_PORT=	japanese/${PORTNAME}
ko_PORT=	korean/${PORTNAME}
pl_PORT=	polish/${PORTNAME}
pt_BR_PORT=	portuguese/${PORTNAME}-pt_BR
pt_PORT=	portuguese/${PORTNAME}
ru_PORT=	russian/${PORTNAME}
uk_PORT=	ukrainian/${PORTNAME}
zh_CN_PORT=	chinese/${PORTNAME}-zh_CN
zh_TW_PORT=	chinese/${PORTNAME}-zh_TW
vi_PORT=	vietnamese/${PORTNAME}

OPTIONS_DEFINE=	ALL
ALL_DESC=	All locatizations data
OPTIONS_DEFAULT=	ALL

.for lang in ${LO_LANG_ALL}
${lang}_DETECT?=	${PREFIX}/lib/${PORTNAME}/readmes/README_${lang:S/_/-/}
${lang}_PORT?=		editors/${PORTNAME}-${lang}
${lang}_NAME?=		${lang}
OPTIONS_DEFINE+=	${lang}
${lang}_DESC=		${${lang}_NAME} localization data
.endfor

.include <bsd.port.options.mk>

.for lang in ${LO_LANG_ALL}
.if ${PORT_OPTIONS:MALL} || ${PORT_OPTIONS:M${lang}}
RUN_DEPENDS+=	${${lang}_DETECT}:${PORTSDIR}/${${lang}_PORT}
.endif
.endfor

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
