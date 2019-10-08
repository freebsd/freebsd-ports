# $FreeBSD$

PORTNAME=	libdrm
PORTVERSION=	2.4.97
DISTVERSIONSUFFIX=	-2.el7
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Interface to kernel Direct Rendering Module (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	libpciaccess
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && (${OSVERSION} < 1103501 \
 || (${OSVERSION} >= 1200000 && ${OSVERSION} < 1201501) \
 || (${OSVERSION} >= 1300000 && ${OSVERSION} < 1300048))
PORTVERSION=	2.4.91
DISTVERSIONSUFFIX=	-3.el7

LINUX_DIST_VER=	7.6.1810

post-install:
	${MV} ${STAGEDIR}${DOCSDIR}/README ${STAGEDIR}${DOCSDIR}/README.rst
.endif

.include <bsd.port.mk>
