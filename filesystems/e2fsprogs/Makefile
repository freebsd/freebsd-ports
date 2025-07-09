PORTNAME=	e2fsprogs
CATEGORIES=	filesystems sysutils
PORTVERSION=	1.47.3
PORTREVISION=	0
BUILD_DEPENDS=	e2fsprogs-core=${PORTVERSION}${${PORTREVISION} > 0:?_${PORTREVISION}:}:filesystems/e2fsprogs-core
RUN_DEPENDS=	${BUILD_DEPENDS}
DISTFILES=	# empty
NO_BUILD=	yes
LICENSE=	GPLv2+
USES=		cpe
CPE_VENDOR=	e2fsprogs_project

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Wrapper to install e2fsprogs into /sbin

do-install:
		${MKDIR} 				${STAGEDIR}/sbin
		${CP} -p ${LOCALBASE}/sbin/fsck_ext2fs	${STAGEDIR}/sbin
		${CP} -p ${LOCALBASE}/sbin/e2fsck	${STAGEDIR}/sbin

.include <bsd.port.mk>
