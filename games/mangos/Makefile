# New ports collection makefile for:	mangos
# Date created:		15 March 2007
# Whom:			Artemiy Kropachev <neon_cyrex@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	mangos
PORTVERSION=	3909
CATEGORIES=	games
MASTER_SITES=	CENKES http://mangos-port.by.ru/ \
		http://neon.heavennet.ru/mangos/
DISTFILES=	${PORTNAME}-${DISTVERSION}${EXTRACT_SUFX}
SCRIPTDEV2REV=	58

MAINTAINER=    	neon_cyrex@mail.ru
COMMENT=	Free dedicated-server for World of Warcraft

OPTIONS=	SCRIPTDEV2	"ScriptDev2"	on \
		CLI		"Command Line Itrerface support" off \
		RA		"Remote Administration support" off \
		DBC		"Install DBC files" on \
		HONORRATE	"Enable HonorRate patch" on

USE_AUTOTOOLS=	aclocal:19 libtoolize autoconf:261 autoheader:261 automake:19 libtool:15
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	-a
USE_MYSQL=	yes
CFLAGS+=	-O0
USE_LDCONFIG=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS= --prefix=${PREFIX} --sysconfdir=${PREFIX}/etc --datadir=${PREFIX}/share
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

.ifdef WITH_SCRIPTDEV2
DISTFILES+=	ScriptDev2-${SCRIPTDEV2REV}.tar.gz
EXTRA_PATCHES=	${FILESDIR}/ScriptDev2.patch
PLIST_SUB+=	SD2=""
.else
PLIST_SUB+=	SD2="@comment "
.endif
.ifdef WITH_DBC
PLIST_SUB+=	DBC=""
DISTFILES+=	mangos-dbc2.tar.gz
.else
PLIST_SUB+=	DBC="@comment "
.endif
.ifdef WITH_HONORRATE
EXTRA_PATCHES+=	${FILESDIR}/HonorRate.patch
.endif
.ifdef WITH_CLI
CONFIGURE_ARGS+=--enable-cli
.endif
.ifdef WITH_RA
CONFIGURE_ARGS+=--enable-ra
.endif

post-extract:
.ifdef WITH_SCRIPTDEV2
	@${MV} ${WRKDIR}/ScriptDev2-${SCRIPTDEV2REV} ${WRKSRC}/src/bindings/ScriptDev2/
.endif
	@${LN} -s ${LTMAIN} ${WRKSRC}/

post-patch:
	@${REINPLACE_CMD} -Ee 's!../etc/(mangos|realm)d.conf!${PREFIX}/etc/\1d.conf!g' \
		${WRKSRC}/src/shared/SystemConfig.h.in
	@${REINPLACE_CMD} -e 's|@MANGOSD_DATA@|${PREFIX}/share/mangos|g' \
		${WRKSRC}/src/mangosd/mangosd.conf.in
	@${REINPLACE_CMD} -e '/^sysconf_DATA/,/conf/d' \
		${WRKSRC}/src/mangosd/Makefile.am ${WRKSRC}/src/realmd/Makefile.am

run-autotools-automake:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} ${AUTOMAKE_ARGS})
.ifdef WITH_SCRIPTDEV2
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} \
		${AUTOMAKE_ARGS} src/bindings/ScriptDev2/Makefile)
.endif

.ifdef WITH_SCRIPTDEV2
post-build:
	@(cd ${BUILD_WRKSRC}/src/bindings/ScriptDev2; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.endif

post-install:
	@for i in mangosd realmd;do cd ${PREFIX}/etc/&&\
		${INSTALL_DATA} ${WRKSRC}/src/$$i/$$i.conf $$i.conf.sample&&\
		${CP} -np $$i.conf.sample $$i.conf;done
.ifdef WITH_SCRIPTDEV2
	@(cd ${INSTALL_WRKSRC}/src/bindings/ScriptDev2 && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.endif
.ifdef WITH_DBC
	@${CP} -Rf ${WRKDIR}/dbc ${PREFIX}/share/mangos/dbc
.endif

.include <bsd.port.post.mk>
