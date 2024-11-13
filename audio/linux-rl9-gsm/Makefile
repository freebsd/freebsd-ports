PORTNAME=	gsm
PORTVERSION=	1.0.19
DISTVERSIONSUFFIX=	-6.el9
PORTREVISION=	1
CATEGORIES=	audio linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	GSM audio codec (Rocky Linux ${LINUX_DIST_VER})
WWW=		http://kbs.cs.tu-berlin.de/~jutta/toast.html

USES=		linux:rl9
USE_LDCONFIG=	yes
USE_LINUX_RPM=	yes
WANT_LINUX32=	yes

DESCR=		${PORTSDIR}/${PKGCATEGORY}/${PORTNAME}/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
