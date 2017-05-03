# $FreeBSD$

PORTNAME=	fastdfs
PORTVERSION=	5.0.10
CATEGORIES=	ftp

MAINTAINER=	daniel@blodan.se
COMMENT=	High performance distributed file system (DFS)

LICENSE=	GPLv3

LIB_DEPENDS=	libfastcommon.so:devel/libfastcommon

USES=		perl5
USE_LDCONFIG=	yes

USE_RC_SUBR=	fdfs_storaged fdfs_trackerd
USERS=		_fastdfs
GROUPS=		_fastdfs

USE_GITHUB=	yes
GH_ACCOUNT=	happyfish100
GH_TAGNAME=	bcb7c56

MAKE_ENV+= 	DESTDIR=${STAGEDIR}

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} make.sh

do-install:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} make.sh install
	@${MKDIR} ${STAGEDIR}/var/db/fastdfs
	@${MKDIR} ${STAGEDIR}/var/db/fastdfs/tracker
	@${MKDIR} ${STAGEDIR}/var/db/fastdfs/storage

.include <bsd.port.mk>
