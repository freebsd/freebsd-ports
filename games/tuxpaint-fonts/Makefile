# New ports collection makefile for:	tuxpaint-fonts
# Date created:				15 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint
PORTVERSION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-fonts

MAINTAINER=	alejandro@varnet.biz
COMMENT=	TuxPaint Localized Fonts

RUN_DEPENDS=	tuxpaint:${PORTSDIR}/games/tuxpaint

DISTFILES=	#
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

# Available font languages
LANGS=		Chinese Chinese_Simplified Chinese_Traditional Georgian Greek \
		Hebrew Hindi Japanese Korean Tamil Thai Vietnamese

# Define distfiles for all languages

CHINESE_DISTFILES=		${PORTNAME}-ttf-chinese-2003.01.05
CHINESE_SIMPLIFIED_DISTFILES=	${PORTNAME}-ttf-chinese-simplified-2004.06.05
CHINESE_TRADITIONAL_DISTFILES=	${PORTNAME}-ttf-chinese-traditional-2004.06.05
GEORGIAN_DISTFILES=		${PORTNAME}-ttf-georgian-2005.03.24
GREEK_DISTFILES=		${PORTNAME}-ttf-greek-2003.01.13
HEBREW_DISTFILES=		${PORTNAME}-ttf-hebrew-2003.08.05
HINDI_DISTFILES=		${PORTNAME}-ttf-hindi-2004.06.19
JAPANESE_DISTFILES=		${PORTNAME}-ttf-japanese-2003.01.24
KOREAN_DISTFILES=		${PORTNAME}-ttf-korean-2002.12.05
TAMIL_DISTFILES=		${PORTNAME}-ttf-tamil-2003.12.26
THAI_DISTFILES=			${PORTNAME}-ttf-thai-2005.07.14
VIETNAMESE_DISTFILES=		${PORTNAME}-ttf-vietnamese-2004.04.15

# Define language codes

CHINESE_CODE=			zh
CHINESE_SIMPLIFIED_CODE=	zh_cn
CHINESE_TRADITIONAL_CODE=	zh_tw
GEORGIAN_CODE=			ka
GREEK_CODE=			el
HEBREW_CODE=			he
HINDI_CODE=			hi
JAPANESE_CODE=			ja
KOREAN_CODE=			ko
TAMIL_CODE=			ta
THAI_CODE=			th
VIETNAMESE_CODE=		vi

# Generate options menu

.for l in ${LANGS}
OPTIONS+=	${l:U} "${l:S/_/ /} fonts" on
.endfor

# Do not use the same OPTIONS directory as "games/tuxpaint"

LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

# Set DISTFILES and PLIST_FILES according to OPTIONS

.for l in ${LANGS:U}
.	if defined(WITH_${l})
DISTFILES+=	${${l}_DISTFILES}${EXTRACT_SUFX}
PLIST_FILES+=	%%DATADIR%%/fonts/locale/${${l}_CODE}.ttf
.	endif
.endfor

# Register font directory

PLIST_DIRS=	%%DATADIR%%/fonts/locale

# Install seleted fonts

do-install:
	@${MKDIR} ${DATADIR}/fonts/locale
.for l in ${LANGS}
.	if defined(WITH_${l:U})
		@${INSTALL_DATA} \
			${WRKSRC}/${${l:U}_DISTFILES}/${${l:U}_CODE}.ttf \
				${DATADIR}/fonts/locale
.	endif
.endfor

.include <bsd.port.post.mk>
