# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	tuxpaint
PORTVERSION=	2004.06.05
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	#
PKGNAMESUFFIX=	-fonts
DISTFILES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TuxPaint Localized Fonts

RUN_DEPENDS=	tuxpaint>=0.9.21:games/tuxpaint

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

# Available font languages.
LANGS=		Chinese_Simplified Korean Vietnamese

# Define distfiles for all languages.
CHINESE_SIMPLIFIED_DISTNAME=	chinese-simplified-2004.06.05
KOREAN_DISTNAME=		korean-2002.12.05
VIETNAMESE_DISTNAME=		vietnamese-2004.04.15

# Define language codes.
CHINESE_SIMPLIFIED_CODE=	zh_cn
KOREAN_CODE=			ko
VIETNAMESE_CODE=		vi

# Generate options menu.
.for l in ${LANGS}
OPTIONS_DEFINE+=	${l:tu}
OPTIONS_DEFAULT+=	${l:tu}
${l:tu}_DESC=	${l:S/_/ /} fonts
.endfor

# Set MASTER_SITES
.for l in ${LANGS}
MASTER_SITES+=	SF/${PORTNAME}/${PORTNAME}-fonts/${${l:tu}_DISTNAME}:${l:tu}
.endfor

.include <bsd.port.options.mk>

# Set DISTFILES and PLIST_FILES according to OPTIONS.
.for l in ${LANGS}
.	if ${PORT_OPTIONS:M${l:tu}}
DISTFILES+=	${PORTNAME}-ttf-${${l:tu}_DISTNAME}${EXTRACT_SUFX}:${l:tu}
PLIST_FILES+=	%%DATADIR%%/fonts/locale/${${l:tu}_CODE}.ttf
PLIST_FILES+=	%%DATADIR%%/fonts/locale/${${l:tu}_CODE}_docs/COPYING.txt
PLIST_FILES+=	%%DATADIR%%/fonts/locale/${${l:tu}_CODE}_docs/README.txt
PLIST_DIRS+=	%%DATADIR%%/fonts/locale/${${l:tu}_CODE}_docs
.	endif
.endfor

# Install seleted fonts.
do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/fonts/locale
.for l in ${LANGS}
.	if ${PORT_OPTIONS:M${l:tu}}
		${INSTALL_DATA} \
			${WRKSRC}/${PORTNAME}-ttf-${${l:tu}_DISTNAME}/${${l:tu}_CODE}.ttf \
			${STAGEDIR}${DATADIR}/fonts/locale
		@${MKDIR} ${STAGEDIR}${DATADIR}/fonts/locale/${${l:tu}_CODE}_docs
		${INSTALL_DATA} \
			${WRKSRC}/${PORTNAME}-ttf-${${l:tu}_DISTNAME}/*.txt \
			${STAGEDIR}${DATADIR}/fonts/locale/${${l:tu}_CODE}_docs
.	endif
.endfor

.include <bsd.port.mk>
