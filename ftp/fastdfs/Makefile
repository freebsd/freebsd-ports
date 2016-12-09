# $FreeBSD$

PORTNAME=	fastdfs
PORTVERSION=	5.0.8
CATEGORIES=	ftp

MAINTAINER=	daniel@blodan.se
COMMENT=	High performance distributed file system (DFS)

LICENSE=	GPLv3

IGNORE_FreeBSD_9_i386=	Does not build properly

LIB_DEPENDS=	libfastcommon.so:devel/libfastcommon

USES=		perl5
USE_LDCONFIG=	yes

USE_RC_SUBR=	fdfs_storaged fdfs_trackerd
USERS=		_fastdfs
GROUPS=		_fastdfs

USE_GITHUB=	yes
GH_ACCOUNT=	happyfish100
GH_TAGNAME=	87659981148a362812912b6d4752d281ac05f0b6

MAKE_ENV += 	DESTDIR=${STAGEDIR}

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} make.sh

do-install:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} make.sh install
	@${INSTALL} -d ${STAGEDIR}/var/db/fastdfs
	@${INSTALL} -d ${STAGEDIR}/var/db/fastdfs/tracker
	@${INSTALL} -d ${STAGEDIR}/var/db/fastdfs/storage

.include <bsd.port.mk>
