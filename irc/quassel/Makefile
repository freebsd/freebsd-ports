# New ports collection makefile for:	quassel
# Date created:		2008-08-10
# Whom:			Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quassel
PORTVERSION=	0.8.0
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://www.quassel-irc.org/pub/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Qt4 based distributed IRC client

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT4=	qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

OPTIONS_MULTI=	MODULE
OPTIONS_MULTI_MODULE=	MONO CORE CLIENT
OPTIONS_DEFAULT=	${OPTIONS_MULTI_MODULE}

MONO_DESC=	Quassel standalone client
CORE_DESC=	Quassel core
CLIENT_DESC=	Quassel client

CMAKE_ARGS+=	-DWANT_MONO=${QUASSEL_MONO} \
		-DWANT_CORE=${QUASSEL_CORE} \
		-DWANT_QTCLIENT=${QUASSEL_CLIENT} \
		-DWITH_LIBINDICATE=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_QT4+=	linguist_build
.endif

.if !${PORT_OPTIONS:MMONO} && !${PORT_OPTIONS:MCLIENT}
PLIST_SUB+=	MONO_OR_CLIENT="@comment "
.else
PLIST_SUB+=	MONO_OR_CLIENT=""
.endif

.if ${PORT_OPTIONS:MMONO}
USE_QT4+=	dbus gui network script sql xml webkit
QUASSEL_MONO=	ON
PLIST_SUB+=	MONO=""
.else
QUASSEL_MONO=	OFF
PLIST_SUB+=	MONO="@comment "
.endif

.if ${PORT_OPTIONS:MCORE}
USE_QT4+=	network script sql sql-sqlite3_run
QUASSEL_CORE=	ON
PLIST_SUB+=	CORE=""

USE_RC_SUBR=	quasselcore
USERS=		quasselcore
GROUPS=		${USERS}
SUB_FILES=	pkg-message
.else
QUASSEL_CORE=	OFF
PLIST_SUB+=	CORE="@comment "
.endif

.if ${PORT_OPTIONS:MCLIENT}
USE_QT4+=	dbus gui network xml webkit
QUASSEL_CLIENT=	ON
PLIST_SUB+=	CLIENT=""
.else
QUASSEL_CLIENT=	OFF
PLIST_SUB+=	CLIENT="@comment "
.endif

pre-configure:
.if !${PORT_OPTIONS:MNLS}
	${REINPLACE_CMD} -e '/add_subdirectory(i18n)/d' \
		${WRKSRC}/CMakeLists.txt
.endif

post-install:
.if ${PORT_OPTIONS:MCORE}
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
