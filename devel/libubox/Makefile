# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libubox
DISTVERSION=	20180802
DISTVERSIONSUFFIX=	-c83a84af
CATEGORIES=	devel
MASTER_SITES=	LOCAL/mm/openwrt

MAINTAINER=	mm@FreeBSD.org
COMMENT=	C utility functions for OpenWrt

LICENSE=	GPLv2

USES=		cmake lua:51 tar:xz
LIBUBOX_GITURL=	https://git.openwrt.org/project/libubox.git

.include <bsd.port.pre.mk>

CMAKE_ARGS+=	-DLUAPATH="${LUA_MODLIBDIR}"

maintainer-fetch:
	@${MAKE} clean
	@${MKDIR} ${WRKSRC}
	@git clone ${LIBUBOX_GITURL} ${WRKSRC}
	@cd ${WRKSRC} && git reset --hard ${DISTVERSIONSUFFIX:S|^-||}
	@${TAR} -c -J -f ${_DISTDIR:S|/$||}/${DISTFILES:M${PORTNAME}-*} \
		-C ${WRKDIR} --exclude .git ${WRKSRC:S|${WRKDIR}/||}
	@${MAKE} makesum
	@${MAKE} clean

.include <bsd.port.post.mk>
