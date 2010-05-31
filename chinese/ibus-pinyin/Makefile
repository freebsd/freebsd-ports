# New ports collection makefile for:	zh-ibus-pinyin
# Date created:				21 October 2008
# Whom:					Henry Hu <henry.hu.sh@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ibus-pinyin
PORTVERSION=	1.2.0.20090915
PORTREVISION=	3
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DBTAR}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	PinYin engine for IBus

RUN_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

USE_PYTHON=	yes
USE_GNOME=	pygtk2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking

PROJECTHOST=	ibus
DBVER=		0.1.10.6
DBTAR=		pinyin-database-${DBVER}.tar.bz2

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-extract:
	${MV} ${WRKDIR}/py.db ${WRKSRC}/engine/
	${TOUCH} ${WRKSRC}/engine/${DBTAR}

.include <bsd.port.mk>
