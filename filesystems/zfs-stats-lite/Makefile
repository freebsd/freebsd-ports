PORTNAME=	zfs-stats-lite
DISTVERSION=	1.5
CATEGORIES=	filesystems sysutils

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	Display human-readable ZFS statistics

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD

CONFLICTS_INSTALL=	zfs-stats

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/zfs-stats

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/zfs-stats ${STAGEDIR}${PREFIX}/bin/zfs-stats

.include <bsd.port.mk>
