# New ports collection makefile for:	tuxpaint-fonts
# Date created:				15 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint
PORTVERSION=	2004.06.05
CATEGORIES=	games
MASTER_SITES=	#
PKGNAMESUFFIX=	-fonts
DISTFILES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	TuxPaint Localized Fonts

RUN_DEPENDS=	tuxpaint>=0.9.21:${PORTSDIR}/games/tuxpaint

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
OPTIONS+=	${l:U} "${l:S/_/ /} fonts" on
.endfor

# Set MASTER_SITES
.for l in ${LANGS}
MASTER_SITES+=	SF/${PORTNAME}/${PORTNAME}-fonts/${${l:U}_DISTNAME}:${l:U}
.endfor

# Do not use the same OPTIONS directory as "games/tuxpaint".
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

# Set DISTFILES and PLIST_FILES according to OPTIONS.
.for l in ${LANGS}
.	if !defined(WITHOUT_${l:U})
DISTFILES+=	${PORTNAME}-ttf-${${l:U}_DISTNAME}${EXTRACT_SUFX}:${l:U}
PLIST_FILES+=	%%DATADIR%%/fonts/locale/${${l:U}_CODE}.ttf
PLIST_FILES+=	%%DATADIR%%/fonts/locale/${${l:U}_CODE}_docs/COPYING.txt
PLIST_FILES+=	%%DATADIR%%/fonts/locale/${${l:U}_CODE}_docs/README.txt
PLIST_DIRS+=	%%DATADIR%%/fonts/locale/${${l:U}_CODE}_docs
.	endif
.endfor

# Install seleted fonts.
do-install:
	${MKDIR} ${DATADIR}/fonts/locale
.for l in ${LANGS}
.	if defined(WITH_${l:U})
		${INSTALL_DATA} \
			${WRKSRC}/${PORTNAME}-ttf-${${l:U}_DISTNAME}/${${l:U}_CODE}.ttf \
			${DATADIR}/fonts/locale
		${MKDIR} ${DATADIR}/fonts/locale/${${l:U}_CODE}_docs
		${INSTALL_DATA} \
			${WRKSRC}/${PORTNAME}-ttf-${${l:U}_DISTNAME}/*.txt \
			${DATADIR}/fonts/locale/${${l:U}_CODE}_docs
.	endif
.endfor

.include <bsd.port.post.mk>
