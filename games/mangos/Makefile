# Created by: Artemiy Kropachev <neon_cyrex@mail.ru>
# $FreeBSD$

PORTNAME=	mangos
PORTVERSION=	5101
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	CENKES http://mangos-port.by.ru/ \
		http://wow.omsktele.com/src/ \
		http://belnetwork.org/mangos/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
SCRIPTDEV2REV=	245

MAINTAINER=    	neon_cyrex@mail.ru
COMMENT=	Free dedicated-server for World of Warcraft

BROKEN=		Fails with newer autotools

OPTIONS_DEFINE=	SCRIPTDEV2 CLI RA DBC
SCRIPTDEV2_DESC=	ScriptDev2 support
CLI_DESC=	Command Line Itrerface support
RA_DESC=	Remote Administration support
DBC_DESC=	Install DBC files

OPTIONS_DEFAULT=	SCRIPTDEV2 DBC

USE_AUTOTOOLS=	aclocal libtoolize autoconf autoheader automake libtool
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	-a
USE_MYSQL=	yes
CFLAGS+=	-O0
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS= --prefix=${PREFIX} --sysconfdir=${PREFIX}/etc --datadir=${PREFIX}/share

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSCRIPTDEV2}
DISTFILES+=	ScriptDev2-${SCRIPTDEV2REV}.tar.gz
EXTRA_PATCHES=	${FILESDIR}/ScriptDev2.patch
PLIST_SUB+=	SD2=""
.else
PLIST_SUB+=	SD2="@comment "
.endif
.if ${PORT_OPTIONS:MDBC}
PLIST_SUB+=	DBC=""
DISTFILES+=	mangos-dbc2_3_0.tar.gz
.else
PLIST_SUB+=	DBC="@comment "
.endif
.if ${PORT_OPTIONS:MCLI}
CONFIGURE_ARGS+=--enable-cli
.endif
.if ${PORT_OPTIONS:MRA}
CONFIGURE_ARGS+=--enable-ra
.endif

post-extract:
.if ${PORT_OPTIONS:MSCRIPTDEV2}
	@${MV} ${WRKDIR}/ScriptDev2-${SCRIPTDEV2REV} ${WRKSRC}/src/bindings/ScriptDev2/
.endif
	@${LN} -s ${LTMAIN} ${WRKSRC}/
	@${RM} ${WRKSRC}/sql/updates/Makefile.am
	@cd ${WRKSRC}/sql/ && ${TAR} -czf updates.tar.gz updates

post-patch:
	@${REINPLACE_CMD} -e 's|@MANGOSD_DATA@|${PREFIX}/share/mangos|g' \
		${WRKSRC}/src/mangosd/mangosd.conf.in
	@${REINPLACE_CMD} -e '/^sysconf_DATA/,/conf/d' \
		${WRKSRC}/src/mangosd/Makefile.am ${WRKSRC}/src/realmd/Makefile.am
.if ${PORT_OPTIONS:MSCRIPTDEV2}
	@cd ${WRKSRC}/src/bindings/ScriptDev2/sql/Updates/&&\
		${REINPLACE_CMD} -e '/pkgdata_DATA/,$$d' Makefile.am\
		&&${ECHO_CMD} "pkgdata_DATA=`echo *.sql`">>Makefile.am
.endif

run-autotools-automake:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} ${AUTOMAKE_ARGS})
.if ${PORT_OPTIONS:MSCRIPTDEV2}
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS} src/bindings/ScriptDev2/Makefile)
.endif

.if ${PORT_OPTIONS:MSCRIPTDEV2}
post-build:
	@(cd ${BUILD_WRKSRC}/src/bindings/ScriptDev2; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endif

post-install:
	@for i in mangosd realmd;do cd ${PREFIX}/etc/&&\
		${INSTALL_DATA} ${WRKSRC}/src/$$i/$$i.conf $$i.conf.sample&&\
		${CP} -np $$i.conf.sample $$i.conf || ${TRUE} ;done
.if ${PORT_OPTIONS:MSCRIPTDEV2}
	@(cd ${INSTALL_WRKSRC}/src/bindings/ScriptDev2 && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif
.if ${PORT_OPTIONS:MDBC}
	@${CP} -Rf ${WRKDIR}/dbc ${PREFIX}/share/mangos/dbc
.endif

.include <bsd.port.mk>
