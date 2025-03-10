PORTNAME=	libtool-ltdl
PORTVERSION=	2.4.6
DISTVERSIONSUFFIX=	-46.el9
PORTREVISION=	2
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Runtime libraries for GNU libtool (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.gnu.org/software/libtool/

LICENSE=	LGPL21+

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

SRC_DISTFILES=	${DISTNAME:S/-ltdl//}${SRC_SUFX}:SOURCE

CONFLICTS=      linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/libltdl/pkg-descr
DOCSDIR=        ${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

OPTIONS_DEFINE= DOCS

.include <bsd.port.mk>
