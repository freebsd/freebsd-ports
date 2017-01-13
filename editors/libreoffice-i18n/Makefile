# $FreeBSD$

.include "${.CURDIR}/../../editors/libreoffice/Makefile.common"

PORTREVISION=	0
PKGNAMESUFFIX=	-i18n

COMMENT=	Localized interface for libreoffice

USES=		metaport

LO_LANG_ALL=	af am ar as ast be bg bn bn_IN bo br brx bs ca ca_valencia \
		cs cy da de dgo dz el en_GB en_ZA eo es et eu fa fi fr ga \
		gd gl gu gug he hi hr hu id is it ja ka kk km kmr_Latn kn \
		ko kok ks lb lo lt lv mai mk ml mn mni mr my nb ne nl nn \
		nr nso oc om or pa_IN pl pt_BR pt ro ru rw sa_IN sat sd si \
		sid sk sl sq sr sr_Latn ss st sv sw_TZ ta te tg th tn tr \
		ts tt ug uk uz ve vec vi xh zh_CN zh_TW zu

AR_PORT=	arabic/${PORTNAME}
DE_PORT=	german/${PORTNAME}
FR_PORT=	french/${PORTNAME}
HE_PORT=	hebrew/${PORTNAME}
HU_PORT=	hungarian/${PORTNAME}
JA_PORT=	japanese/${PORTNAME}
KO_PORT=	korean/${PORTNAME}
PL_PORT=	polish/${PORTNAME}
PT_BR_PORT=	portuguese/${PORTNAME}-pt_BR
PT_PORT=	portuguese/${PORTNAME}
RU_PORT=	russian/${PORTNAME}
UK_PORT=	ukrainian/${PORTNAME}
ZH_CN_PORT=	chinese/${PORTNAME}-zh_CN
ZH_TW_PORT=	chinese/${PORTNAME}-zh_TW
VI_PORT=	vietnamese/${PORTNAME}

OPTIONS_MULTI=		LANG
OPTIONS_MULTI_LANG=	${LO_LANG_ALL:tu}
OPTIONS_DEFAULT=	${LO_LANG_ALL:tu}

.for lang in ${LO_LANG_ALL}
${lang}_DETECT?=	${LOCALBASE}/lib/${PORTNAME}/readmes/README_${lang:S/_/-/}
${lang}_NAME?=		${lang}
${lang:tu}_PORT?=	editors/${PORTNAME}-${lang}
${lang:tu}_DESC=	${${lang}_NAME} localization data
${lang:tu}_RUN_DEPENDS=	${${lang}_DETECT}:${${lang:tu}_PORT}
.endfor

all-lang-list:
.for lang in ${LO_LANG_ALL}
	@${ECHO} ${lang}
.endfor

all-help-list:
.for lang in ${LO_LANG_ALL}
	@${EGREP} -q '^[:blank:]*LO_HAS_HELPPACK[:blank:]*=' \
	    ${.CURDIR}/../../${${lang:tu}_PORT}/Makefile && ${ECHO} "${lang}" \
	    || true
.endfor

all-makesum:
.for lang in ${LO_LANG_ALL}
	@cd ${.CURDIR}/../../${${lang:tu}_PORT} && ${MAKE} makesum
.endfor

.include <bsd.port.mk>
