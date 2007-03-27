# New ports collection makefile for:   mangos
# Date created:        15 march 2007
# Whom: neon
#
# $FreeBSD$
#

PORTNAME=	mangos
PORTVERSION=	3389
CATEGORIES=	games
MASTER_SITES=	http://neon.heavennet.ru/mangos/

MAINTAINER=	neon_cyrex@mail.ru
COMMENT=	Free dedicated-server for World of Warcraft

OPTIONS=	SCRIPTDEV2	"ScriptDev2"	on \
		CLI		"Command Line Itrerface support" on \
		RA		"Remote Administration support" on \
		DBC		"Install DBC files" on

.include <bsd.port.pre.mk>

DISTFILES=${PORTNAME}-${PORTVERSION}.tar.gz
.if defined(WITH_SCRIPTDEV2)
    DISTFILES+= ScriptDev2-29.tar.gz
.endif

.if defined(WITH_DBC)
    DISTFILES+= mangos-dbc.tar.gz
.endif

USE_AUTOTOOLS=	aclocal:19 libtoolize autoconf:261 autoheader:261 automake:19 libtool:15
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	-a
USE_MYSQL=	yes
CFLAGS:=	${CFLAGS:N-O*} -O0
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--prefix=${PREFIX} --sysconfdir=${PREFIX}/etc --datadir=${PREFIX}/share

.if defined(WITH_SCRIPTDEV2)
    EXTRA_PATCHES=${FILESDIR}/configure.ac.patch
.endif

.if defined(WITH_CLI)
    CONFIGURE_ARGS+= --with-cli
.endif

.if defined(WITH_RA)
    CONFIGURE_ARGS+= --with-ra
.endif

post-extract:
.if defined(WITH_SCRIPTDEV2)
	@(${MV} ${WRKDIR}/ScriptDev2-29  ${WRKDIR}/${PORTNAME}-${PORTVERSION}/src/bindings/ScriptDev2)
.endif
	${LN} -s ${LTMAIN} ${WRKDIR}/${PORTNAME}-${PORTVERSION}/
	@${REINPLACE_CMD} -e "s|@MANGOSD_CONFIG@|${PREFIX}/etc/mangosd.conf|g" ${WRKDIR}/${PORTNAME}-${PORTVERSION}/src/shared/SystemConfig.h.in
	@${REINPLACE_CMD} -e "s|@REALMD_CONFIG@|${PREFIX}/etc/realmd.conf|g" ${WRKDIR}/${PORTNAME}-${PORTVERSION}/src/shared/SystemConfig.h.in
	@${REINPLACE_CMD} -e "s|@MANGOSD_DATA@|${PREFIX}/share/mangos|g" ${WRKDIR}/${PORTNAME}-${PORTVERSION}/src/mangosd/mangosd.conf.in

run-autotools-automake:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} ${AUTOMAKE_ARGS})
.if defined(WITH_SCRIPTDEV2)
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} ${AUTOMAKE_ARGS} src/bindings/ScriptDev2/Makefile)
.endif

do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.if defined(WITH_SCRIPTDEV2)
	@(cd ${BUILD_WRKSRC}/src/bindings/ScriptDev2; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endif

do-install:
	@(cd ${INSTALL_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.if defined(WITH_SCRIPTDEV2)
	@(cd ${INSTALL_WRKSRC}/src/bindings/ScriptDev2 && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif

.if defined(WITH_DBC)
	@(${MV} ${WRKDIR}/dbc ${PREFIX}/share/mangos/dbc)
PLIST_SUB+=	DBC=""
.else
PLIST_SUB+=	DBC="@comment "
.endif

.include <bsd.port.post.mk>
