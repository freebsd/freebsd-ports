# New ports collection makefile for:	zh-ibus-pinyin
# Date created:				21 October 2008
# Whom:					Henry Hu <henry.hu.sh@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ibus-pinyin
PORTVERSION=	1.3.8
CATEGORIES=	chinese
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DBTAR}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	PinYin engine for IBus

BUILD_DEPENDS=	ibus-daemon:${PORTSDIR}/textproc/ibus \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3 \
		${LOCALBASE}/include/boost/accumulators/accumulators.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	yes
USE_GNOME=	pygtk2

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking

PROJECTHOST=	ibus

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|DATADIRNAME=lib|DATADIRNAME=share|' ${WRKSRC}/configure

.include <bsd.port.mk>
