PORTNAME=	cramfs
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	filesystems sysutils
MASTER_SITES=	SF

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Linux Compressed ROM FileSystem
WWW=		https://sourceforge.net/projects/cramfs/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake

MAKEFILE=	GNUmakefile

PLIST_FILES=	sbin/cramfsck sbin/mkcramfs

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cramfsck ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/mkcramfs ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
