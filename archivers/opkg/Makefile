# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	opkg
DISTVERSION=	20180802
DISTVERSIONSUFFIX=	-3b417b9f
CATEGORIES=	archivers sysutils
MASTER_SITES=	LOCAL/mm/openwrt

MAINTAINER=	mm@FreeBSD.org
COMMENT=	OpenWrt package manager

LICENSE=	GPLv2

OPKG_GITURL=	https://git.openwrt.org/project/opkg-lede.git

USES=		cmake tar:xz
LIB_DEPENDS+=	libubox.so:devel/libubox

.include <bsd.port.pre.mk>

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS+=	-DLUAPATH="${LUA_MODLIBDIR}" \
		-DPATH_SPEC="${LOCALBASE}/sbin:${LOCALBASE}/bin:/usr/sbin:/usr/bin:/sbin:/bin"

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/opkg.conf,${PREFIX}/etc/opkg.conf,g' \
		${WRKSRC}/src/opkg-cl.c
	@${REINPLACE_CMD} -e 's,ROOT="",ROOT="${PREFIX}",g' \
		${WRKSRC}/utils/opkg-key
	@${REINPLACE_CMD} -e \
		's,OPKGETCDIR="/etc",OPKGETCDIR="${PREFIX}/etc",g' \
		${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e 's,@PACKAGE_NAME@,opkg-cl,g' \
		-e 's,@PACKAGE_STRING@,opkg-cl,g' \
		-e 's|@CLEAN_DATE@|October 5, 2010|g' \
		${WRKSRC}/man/opkg-cl.1.in
	@${REINPLACE_CMD} -e 's,@PACKAGE_NAME@,opkg-key,g' \
		-e 's,@PACKAGE_STRING@,opkg-key,g' \
		-e 's|@CLEAN_DATE@|October 8, 2010|g' \
		${WRKSRC}/man/opkg-key.1.in

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/utils/opkg-key ${STAGEDIR}${PREFIX}/bin
.for file in opkg-cl.1 opkg-key.1
	${INSTALL_MAN} ${WRKSRC}/man/${file}.in \
		${STAGEDIR}${MANPREFIX}/man/man1/${file}
.endfor

maintainer-fetch:
	@${MAKE} clean
	@${MKDIR} ${WRKSRC}
	@git clone ${OPKG_GITURL} ${WRKSRC}
	@cd ${WRKSRC} && git reset --hard ${DISTVERSIONSUFFIX:S|^-||}
	@${TAR} -c -J -f ${_DISTDIR:S|/$||}/${DISTFILES:M${PORTNAME}-*} \
		-C ${WRKDIR} --exclude .git ${WRKSRC:S|${WRKDIR}/||}
	@${MAKE} makesum
	@${MAKE} clean

.include <bsd.port.post.mk>
