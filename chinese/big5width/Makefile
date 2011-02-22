# New ports collection makefile for:	big5width
# Date created:				Sep 20 2006
# Whom:					Rong-En Fan <rafan@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	big5width
PORTVERSION=	1.0
CATEGORIES=	chinese
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Unicode width dirty fix for Big5 font (${LANG} locale)

BASELOCALEDIR=	/usr/share/locale
LOCALEDIR=	${PREFIX}/share/locale
LANG=		zh_TW.UTF-8

PLIST_SUB=	BASELOCALEDIR=${BASELOCALEDIR} \
		LOCALEDIR=${LOCALEDIR} \
		LANG=${LANG}

.include <bsd.port.pre.mk>

SRCDIR=		${SRC_BASE}/share/mklocale

.if !exists(${SRCDIR})
IGNORE=		need to build this port with the locale source
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -R ${SRCDIR} ${WRKSRC}
	@${CP} ${WRKSRC}/UTF-8.src ${WRKSRC}/${LANG}.src

do-build:
	/usr/bin/mklocale -o ${WRKSRC}/LC_CTYPE ${WRKSRC}/${LANG}.src

do-install:
	${MKDIR} ${LOCALEDIR}/${LANG}
	${INSTALL_DATA} ${WRKSRC}/LC_CTYPE ${LOCALEDIR}/${LANG}
	${LN} -fs ${LOCALEDIR}/${LANG}/LC_CTYPE \
		${BASELOCALEDIR}/${LANG}/LC_CTYPE

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
