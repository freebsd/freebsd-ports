PORTNAME=	sqlite
PORTVERSION=	3.34.1
DISTVERSIONSUFFIX=	-7.el9_3
PORTREVISION=	2
CATEGORIES=	databases linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library that implements an embeddable SQL database engine (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.sqlite.org/

LICENSE=	PD

USES=		cpe linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

BIN_DISTNAMES=	${DISTNAME}
LIB_DISTNAMES=	sqlite-libs-${PORTVERSION}${DISTVERSIONSUFFIX}

CONFLICTS=	linux-c7-${PORTNAME}
DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}3/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
