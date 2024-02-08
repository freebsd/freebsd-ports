PORTNAME=	libsigc++20
PORTVERSION=	2.10.7
DISTVERSIONSUFFIX=	-2.el9
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Callback Framework for C++ (Rocky Linux ${LINUX_DIST_VER})
WWW=		http://libsigc.sourceforge.net/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
