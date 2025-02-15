PORTNAME=	zxfer
DISTVERSION=	1.1.7
PORTREVISION=	2
DISTVERSIONPREFIX=	v
CATEGORIES=	filesystems sysutils

PATCH_SITES=	https://github.com/allanjude/zxfer/commit/
PATCHFILES=	88e93145d55024bb49850e97ae1a42a5acfcefc5.diff:-p1

MAINTAINER=	ports@scaleengine.com
COMMENT=	Easily and reliably transfer ZFS filesystems
WWW=		https://github.com/allanjude/zxfer

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	allanjude

NO_BUILD=	yes

OPTIONS_DEFINE=	RSYNC

RSYNC_DESC=		Enable RSYNC Support
RSYNC_RUN_DEPENDS=	rsync:net/rsync

PLIST_FILES=	share/man/man8/zxfer.8.gz \
		sbin/zxfer

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zxfer ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/zxfer.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
