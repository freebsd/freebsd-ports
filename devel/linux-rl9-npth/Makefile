PORTNAME=	npth
PORTVERSION=	1.6
DISTVERSIONSUFFIX=	-8.el9
PORTREVISION=	1
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	New GNU Portable Threads (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.gnupg.org/software/npth/index.html

LICENSE=	LGPL21+

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX=	libgcrypt
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
