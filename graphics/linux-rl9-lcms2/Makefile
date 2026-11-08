PORTNAME=	lcms2
PORTVERSION=	2.12
DISTVERSIONSUFFIX=	-3.el9
CATEGORIES=	graphics linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Little Color Management System (Rocky Linux ${LINUX_DIST_VER})
WWW=		https://www.littlecms.com/

LICENSE=	MIT

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS
OPTIONS_SUB=	yes

.include <bsd.port.mk>
