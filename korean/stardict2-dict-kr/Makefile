# Ports collection makefile for:	stardict-dict-korean
# Date created:				20 May 2007
# Whom:					Yinghong Liu <relaxbsd@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	stardict2-dict-kr
PORTVERSION=	2.4.2
PORTREVISION=	2
CATEGORIES=	korean textproc
MASTER_SITES=	SF/stardict/stardict-dictionaries-ko/${PORTVERSION}
DIST_SUBDIR=	stardict

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Korean and foreign language Dictionaries for StarDict

RUN_DEPENDS=	stardict:${PORTSDIR}/textproc/stardict2

NO_BUILD=	yes
USE_BZIP2=	yes

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}

DICTDIR=	share/stardict/dic

DICTIONARIES=	GPL_korean-russian-dic Hanja_KoreanHanzi_Dic KoreanAnimalMedicalDic \
		KoreanDic KoreanEnglishDic KoreanLawDic KoreanMedicalDic quick_eng-kor

.if !defined(DICT_PACK)
OPTIONS=	ALL "All dictionaries" on
.for dict in ${DICTIONARIES}
OPTIONS+=	${dict:U:S|-|_|g} "${dict} dictionary" off
.endfor
.endif

.include <bsd.port.pre.mk>

.for dict in ${DICTIONARIES}
.if defined(WITH_ALL) || defined(WITH_${dict:U:S|-|_|g})
INSTALL_DICTIONARIES+=	${dict}
.endif
.endfor

.for dict in ${INSTALL_DICTIONARIES}
DISTFILES+=	stardict-${dict}-${PORTVERSION}${EXTRACT_SUFX}
.endfor

do-build:
	@${DO_NADA}

do-install:
	${MKDIR} ${PREFIX}/${DICTDIR}
.for dict in ${INSTALL_DICTIONARIES}
	cd ${WRKDIR}/stardict-${dict}-${PORTVERSION}/ \
	&& ${INSTALL_DATA} * ${PREFIX}/${DICTDIR}/ \
	&& (${FIND} -s * -type f | \
	${SED} -e 's|^|${DICTDIR}/|' >> ${TMPPLIST})
.endfor
	@${ECHO_CMD} "@unexec ${RMDIR} %D/${DICTDIR} 2>/dev/null || true" >> ${TMPPLIST}

.include <bsd.port.post.mk>
