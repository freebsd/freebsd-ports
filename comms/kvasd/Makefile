# $FreeBSD$

PORTNAME=	kvasd
PORTVERSION=	1.0
PORTREVISION=	1
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
		${MKDIR} ${WRKSRC}
		${CP} ${DISTDIR}/kvasd ${WRKSRC}

do-install:
		${BRANDELF} -t Linux ${WRKSRC}/kvasd
		${INSTALL_KLD} ${DISTDIR}/kvasd ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
