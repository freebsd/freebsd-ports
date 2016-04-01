# $FreeBSD$

PORTNAME=	kvasd
PORTVERSION=	1.0
CATEGORIES=	comms hamradio
MASTER_SITES=	https://svn.code.sf.net/p/wsjt/wsjt/trunk/kvasd-binary/Linux/ \
		LOCAL/db
DISTFILES=	kvasd

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Helper program for wsjt and wsjtx

LICENSE=	K1JT
LICENSE_NAME=	Joseph H Taylor, Jr, K1JT.
LICENSE_FILE=	${FILESDIR}/LICENSE.txt
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	${KVASD_DEPENDS}
RUN_DEPENDS=	${KVASD_DEPENDS}

KVASD_DEPENDS=	linux-${USE_LINUX}-libgfortran>0:devel/linux-c6-libgfortran
USE_LINUX=	c6
NO_BUILD=	yes
PLIST_FILES=	bin/kvasd

do-extract:

BINMODE=	0644
do-install:
		${INSTALL_KLD} ${DISTDIR}/kvasd ${STAGEDIR}${PREFIX}/bin
		${BRANDELF} -t Linux ${STAGEDIR}${PREFIX}/bin/kvasd

.include <bsd.port.mk>
