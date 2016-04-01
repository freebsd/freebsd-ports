# Created by: Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
# $FreeBSD$

CATEGORIES=	japanese

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 program that displays images of various formats with japanization

MASTERDIR=	${.CURDIR}/../../graphics/xv
PKGDIR=		${.CURDIR}

MAKE_ENV=	LOCALE_EXTENSION=-DTV_L10N

RUN_DEPENDS=	xv:graphics/xv

PLIST_FILES=	bin/ja-xv

OPTIONS_EXCLUDE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xv ${STAGEDIR}${PREFIX}/bin/ja-xv

.include "${MASTERDIR}/Makefile"
