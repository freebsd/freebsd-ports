# New ports collection makefile for:	superkaramba-lwp
# Date created:				Sun, May 28, 2006
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$

PORTNAME=		lwp
PORTVERSION=		15.0
PORTREVISION=	7
CATEGORIES=		deskutils kde
MASTER_SITES=		http://www.message.co.nz/~matt-sarah/ \
			http://liquidweather.net/
PKGNAMEPREFIX=		superkaramba-
EXTRACT_SUFX=		.skz

MAINTAINER=		bsdkaffee@gmail.com
COMMENT=		Liquid Weather ++ a Superkaramba weather applet

EXTRACT_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS=		zip:${PORTSDIR}/archivers/zip
RUN_DEPENDS=		convert:${PORTSDIR}/graphics/ImageMagick \
			superkaramba:${PORTSDIR}/misc/kdeutils3 \
			${PYTHON_SITELIBDIR}/reportlab/__init__.py:${PORTSDIR}/print/py-reportlab \
			pyuic:${PORTSDIR}/x11-toolkits/py-qt

USE_PYTHON=		yes

WRKSRC=			${WRKDIR}/${DISTNAME}

EXTRACT_CMD=		${UNZIP_CMD}
EXTRACT_BEFORE_ARGS=	-q -d ${DISTNAME}
EXTRACT_AFTER_ARGS=	# empty

NO_BUILD=		yes

PLIST_SUB=		LWPVER=${DISTFILES}

.include <bsd.port.pre.mk>

post-extract:
	@cd ${WRKSRC} && ${REINPLACE_CMD} -e 's|/usr/bin|${LOCALBASE}/bin|' \
		test_gui.py
	@cd ${WRKSRC} && ${RM} *~ splash/digikam3.db

pre-install:
	@cd ${WRKSRC} && zip -qr ${DISTFILES} *

do-install:
	@${MKDIR} ${PREFIX}/share/apps/superkaramba/themes
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DISTFILES} \
		${PREFIX}/share/apps/superkaramba/themes

.include <bsd.port.post.mk>
