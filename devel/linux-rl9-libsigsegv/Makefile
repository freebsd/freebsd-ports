PORTNAME=	libsigsegv
PORTVERSION=	2.13
DISTVERSIONSUFFIX=	-4.el9
CATEGORIES=	devel linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Handling page faults in user mode (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.gnu.org/software/libsigsegv/

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}${PKGNAMESUFFIX}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
