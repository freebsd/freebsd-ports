# $FreeBSD$

PORTNAME=	fastdfs
PORTVERSION=	6.0.6
CATEGORIES=	ftp

MAINTAINER=	daniel@blodan.se
COMMENT=	High performance distributed file system (DFS)

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING-3_0.txt

BROKEN_mips=		fails to link: tracker_service.c:270: undefined reference to '__sync_add_and_fetch_4'
BROKEN_mips64=		fails to link: tracker_service.c:270: undefined reference to '__sync_add_and_fetch_4'

LIB_DEPENDS=	libfastcommon.so:devel/libfastcommon

USES=		perl5
USE_LDCONFIG=	yes

USE_RC_SUBR=	fdfs_storaged fdfs_trackerd
USERS=		_fastdfs
GROUPS=		_fastdfs

USE_GITHUB=	yes
GH_ACCOUNT=	happyfish100
GH_TAGNAME=	V6.06

SUB_FILES=	fdfs_status

MAKE_ENV+=	DESTDIR=${STAGEDIR}

do-build:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} make.sh

do-install:
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} make.sh install
	@${MKDIR} ${STAGEDIR}/var/db/fastdfs
	@${MKDIR} ${STAGEDIR}/var/db/fastdfs/tracker
	@${MKDIR} ${STAGEDIR}/var/db/fastdfs/storage
	${INSTALL_SCRIPT} ${WRKDIR}/fdfs_status ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
