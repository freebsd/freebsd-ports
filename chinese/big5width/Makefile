# Created by: Rong-En Fan <rafan@FreeBSD.org>
# $FreeBSD$

PORTNAME=	big5width
PORTVERSION=	1.0
CATEGORIES=	chinese
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Unicode width dirty fix for Big5 font (${LOCALE} locale)

BASELOCALEDIR=	/usr/share/locale
LOCALEDIR=	${PREFIX}/share/locale
LOCALE=		zh_TW.UTF-8

PLIST_SUB=	BASELOCALEDIR=${BASELOCALEDIR} \
		LOCALEDIR=${LOCALEDIR} \
		LOCALE=${LOCALE}

.include <bsd.port.pre.mk>

SRCDIR=		${SRC_BASE}/share/mklocale

.if !exists(${SRCDIR})
IGNORE=		need to build this port with the locale source
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${CP} -R ${SRCDIR} ${WRKSRC}
	@${CP} ${WRKSRC}/UTF-8.src ${WRKSRC}/${LOCALE}.src

do-build:
	/usr/bin/mklocale -o ${WRKSRC}/LC_CTYPE ${WRKSRC}/${LOCALE}.src

do-install:
	${MKDIR} ${STAGEDIR}${LOCALEDIR}/${LOCALE}
	${INSTALL_DATA} ${WRKSRC}/LC_CTYPE ${STAGEDIR}${LOCALEDIR}/${LOCALE}

.include <bsd.port.post.mk>
