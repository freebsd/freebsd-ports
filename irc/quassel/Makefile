# New ports collection makefile for:	quassel
# Date created:		2008-08-10
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quassel
PORTVERSION=	0.5.1
CATEGORIES=	irc
MASTER_SITES=	http://www.quassel-irc.org/pub/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt4 based distributed IRC client

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build
CMAKE_USE_PTHREAD=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS=	MONO "Quassel standalone client" on \
		CORE "Quassel core" on \
		CLIENT "Quassel client" on

CMAKE_ARGS+=	-DWANT_MONO=${QUASSEL_MONO} \
		-DWANT_CORE=${QUASSEL_CORE} \
		-DWANT_QTCLIENT=${QUASSEL_CLIENT} \
		-DWITH_LIBINDICATE=OFF

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MONO) && defined(WITHOUT_CORE) && defined(WITHOUT_CLIENT)
IGNORE=		needs at least one Quassel component. Please, rerun 'make config'
.endif

.if !defined(WITHOUT_NLS)
QT_COMPONENTS+=	linguist_build
.endif

.if defined(WITHOUT_MONO) && defined(WITHOUT_CLIENT)
PLIST_SUB+=	MONO_OR_CLIENT="@comment "
.else
PLIST_SUB+=	MONO_OR_CLIENT=""
.endif

.if !defined(WITHOUT_MONO)
QT_COMPONENTS+=	dbus gui network script sql xml webkit
QUASSEL_MONO=	ON
PLIST_SUB+=	MONO=""
.else
QUASSEL_MONO=	OFF
PLIST_SUB+=	MONO="@comment "
.endif

.if !defined(WITHOUT_CORE)
QT_COMPONENTS+=	network script sql
QUASSEL_CORE=	ON
PLIST_SUB+=	CORE=""
.else
QUASSEL_CORE=	OFF
PLIST_SUB+=	CORE="@comment "
.endif

.if !defined(WITHOUT_CLIENT)
QT_COMPONENTS+=	dbus gui network xml webkit
QUASSEL_CLIENT=	ON
PLIST_SUB+=	CLIENT=""
.else
QUASSEL_CLIENT=	OFF
PLIST_SUB+=	CLIENT="@comment "
.endif

pre-configure:
.if defined(WITHOUT_NLS)
	${REINPLACE_CMD} -e '/add_subdirectory(i18n)/d' \
		${WRKSRC}/CMakeLists.txt
.endif

.include <bsd.port.post.mk>
