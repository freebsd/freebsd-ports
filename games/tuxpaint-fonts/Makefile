# New ports collection makefile for:	tuxpaint-fonts
# Date created:				15 Jul 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	tuxpaint
PORTVERSION=	1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-fonts/chinese-2003.0${PORTVERSION}.05
PKGNAMESUFFIX=	-fonts
DISTFILES=	#

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	TuxPaint Localized Fonts

RUN_DEPENDS=	tuxpaint:${PORTSDIR}/games/tuxpaint

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

# Available font languages.
LANGS=		Chinese Chinese_Simplified Korean

# Define distfiles for all languages.
CHINESE_DISTFILES=		${PORTNAME}-ttf-chinese-2003.01.05
CHINESE_SIMPLIFIED_DISTFILES=	${PORTNAME}-ttf-chinese-simplified-2004.06.05
KOREAN_DISTFILES=		${PORTNAME}-ttf-korean-2002.12.05

# Define language codes.
CHINESE_CODE=			zh
CHINESE_SIMPLIFIED_CODE=	zh_cn
KOREAN_CODE=			ko

# Generate options menu.
.for l in ${LANGS}
OPTIONS+=	${l:U} "${l:S/_/ /} fonts" on
.endfor

# Do not use the same OPTIONS directory as "games/tuxpaint".
LATEST_LINK=	${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

# Set DISTFILES and PLIST_FILES according to OPTIONS.
.for l in ${LANGS:U}
.	if !defined(WITHOUT_${l})
DISTFILES+=	${${l}_DISTFILES}${EXTRACT_SUFX}
PLIST_FILES+=	%%DATADIR%%/fonts/locale/${${l}_CODE}.ttf
.	endif
.endfor

# Install seleted fonts.
do-install:
	${MKDIR} ${DATADIR}/fonts/locale
.for l in ${LANGS}
.	if defined(WITH_${l:U})
		${INSTALL_DATA} \
			${WRKSRC}/${${l:U}_DISTFILES}/${${l:U}_CODE}.ttf \
			${DATADIR}/fonts/locale
.	endif
.endfor

.include <bsd.port.post.mk>
