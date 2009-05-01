# New ports collection makefile for:	qca
# Date created:				27 March 2005
# Whom:					Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	qca
PORTVERSION=	2.0.2
CATEGORIES=	devel
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/
DISTNAME=	qca-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Cross-platform crypto API for QT

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build
HAS_CONFIGURE=	yes
QT_NONSTANDARD=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX}
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

MAN1=		qcatool2.1

.if defined(MAINTAINER_MODE)
QT_COMPONENTS+=	qtestlib
.else
CONFIGURE_ARGS+=--disable-tests
.endif

.if !defined(WITH_DEBUG)
CONFIGURE_ARGS+=--release --no-separate-debug-info
PLIST_SUB+=	DEBUG="@comment "
.else
CONFIGURE_ARGS+=--debug
PLIST_SUB+=	DEBUG=""
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/configure
	${MKDIR} ${WRKSRC}/libdata/pkgconfig

post-install:
	${STRIP_CMD} ${PREFIX}/bin/qcatool2 ${PREFIX}/lib/libqca.so.${PORTVERSION}

.include <bsd.port.mk>
