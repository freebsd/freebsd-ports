PORTNAME=	opkg
DISTVERSION=	20180803
PORTREVISION=	1
CATEGORIES=	archivers sysutils
PKGNAMESUFFIX=	-openwrt

MAINTAINER=	mm@FreeBSD.org
COMMENT=	OpenWrt package manager

LICENSE=	GPLv2

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	mmatuska
GH_TAGNAME=	b07cde3

BUILD_DEPENDS+=	${LOCALBASE}/lib/libubox.a:devel/libubox

.include <bsd.port.pre.mk>

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CMAKE_ARGS+=	-DLUAPATH="${LUA_MODLIBDIR}" \
		-DSTATIC_UBOX=1 \
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

.include <bsd.port.post.mk>
