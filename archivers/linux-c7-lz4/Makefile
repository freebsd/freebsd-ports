PORTNAME=	lz4
PORTVERSION=	1.8.3
DISTVERSIONSUFFIX=	-1.el7
CATEGORIES=	archivers linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	LZ4 compression library and utilities (Linux CentOS ${LINUX_DIST_VER})
WWW=		https://lz4.github.io/lz4/

LICENSE=	BSD2CLAUSE GPLv2
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=	${WRKSRC}/usr/share/licenses/lz4-1.8.3/LICENSE
LICENSE_FILE_GPLv2=	${WRKSRC}/usr/share/licenses/lz4-1.8.3/COPYING

USES=		cpe linux:c7
CPE_VENDOR=	lz4_project
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../liblz4/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
