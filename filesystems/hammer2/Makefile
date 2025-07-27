PORTNAME=	hammer2
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.12
CATEGORIES=	filesystems

MAINTAINER=	tkusumi@netbsd.org
COMMENT=	HAMMER2 file system for FreeBSD (experimental write support)
WWW=		https://github.com/kusumi/freebsd_hammer2

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		kmod uidfix

USE_GITHUB=	yes
GH_ACCOUNT=	kusumi
GH_PROJECT=	freebsd_hammer2

do-install:
	${INSTALL_KLD} ${WRKSRC}/src/sys/fs/hammer2/hammer2.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/src/sbin/hammer2/hammer2 ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/sbin/newfs_hammer2/newfs_hammer2 ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/sbin/mount_hammer2/mount_hammer2 ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/src/sbin/fsck_hammer2/fsck_hammer2 ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/src/sbin/hammer2/hammer2.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/src/sbin/newfs_hammer2/newfs_hammer2.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/src/sbin/mount_hammer2/mount_hammer2.8 ${STAGEDIR}${PREFIX}/share/man/man8
	${INSTALL_MAN} ${WRKSRC}/src/sbin/fsck_hammer2/fsck_hammer2.8 ${STAGEDIR}${PREFIX}/share/man/man8

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/hammer2
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/newfs_hammer2
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/mount_hammer2
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/fsck_hammer2

.include <bsd.port.mk>
