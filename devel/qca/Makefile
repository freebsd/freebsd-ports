# Created by: Vsevolod Stakhov <vsevolod@highsecure.ru>
# $FreeBSD$

PORTNAME=	qca
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://delta.affinix.com/download/qca/2.0/
DISTNAME=	qca-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Cross-platform crypto API for Qt

USE_BZIP2=	yes
USE_QT4=	corelib qmake_build moc_build
HAS_CONFIGURE=	yes
QT_NONSTANDARD=	yes
CONFIGURE_ARGS+=--prefix=${PREFIX} \
		--disable-tests
CONFIGURE_ENV+=	QMAKESPEC=${QMAKESPEC}
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
DESTDIRNAME=	INSTALL_ROOT

.if defined(PACKAGE_BUILDING)
CONFIGURE_ENV+=	QC_VERBOSE=Y
.endif

OPTIONS_DEFINE=	DEBUG
OPTIONS_SUB=	yes

DEBUG_CONFIGURE_ON=	--debug
DEBUG_CONFIGURE_OFF=	--release --no-separate-debug-info

pre-configure:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/configure
	${MKDIR} ${WRKSRC}/libdata/pkgconfig

.include <bsd.port.mk>
