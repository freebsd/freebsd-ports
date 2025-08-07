PORTNAME=	fusefs-webdavfs
DISTVERSION=	g20200520
PORTREVISION=	29
CATEGORIES=	filesystems

MAINTAINER=	eugen@FreeBSD.org
COMMENT=	FUSE filesystem for WEBDAV shares
WWW=		https://github.com/miquels/webdavfs

LICENSE=	BSD3CLAUSE BSD4CLAUSE MIT
LICENSE_COMB=	multi
LICENSE_FILE_BSD3CLAUSE=	${WRKDIR}/webdavfs-${GH_TAGNAME}/vendor/bazil.org/fuse/LICENSE
LICENSE_FILE_BSD4CLAUSE=	${WRKDIR}/webdavfs-${GH_TAGNAME}/vendor/github.com/pborman/getopt/LICENSE
LICENSE_FILE_MIT=		${WRKDIR}/webdavfs-${GH_TAGNAME}/LICENSE.md
LICENSE_DISTFILES_MIT=		${DISTNAME}${EXTRACT_SUFX}
LICENSE_DISTFILES_BSD3CLAUSE=	bazil-fuse-${FUSE_GH_TAGNAME}_GH0${EXTRACT_SUFX}
LICENSE_DISTFILES_BSD4CLAUSE=	pborman-getopt-${GETOPT_GH_TAGNAME}_GH0${EXTRACT_SUFX}

# This needs to be Go 1.7 or newer.
USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	miquels
GH_PROJECT=	webdavfs
GH_TAGNAME=	117d633

# 2020-12-04 pborman/getopt
GETOPT_GH_TAGNAME=	ee0cd42419d3
# 2020-05-25 bazil/fuse
FUSE_GH_TAGNAME=	65cc252bf669
# 2020-05-20 golang/net
NET_GH_TAGNAME=		59133d7f0dd7

GH_TUPLE=	bazil:fuse:${FUSE_GH_TAGNAME}:bazil_fuse/vendor/bazil.org/fuse \
		golang:net:${NET_GH_TAGNAME}:golang_net/vendor/golang.org/x/net \
		pborman:getopt:${GETOPT_GH_TAGNAME}:pborman_getopt/vendor/github.com/pborman/getopt

GO_TARGET=	:${PREFIX}/sbin/mount.webdavfs

PLIST_FILES=	sbin/mount.webdavfs sbin/mount_webdavfs

SUB_FILES=	pkg-message mount_webdavfs

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mount_webdavfs ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>
