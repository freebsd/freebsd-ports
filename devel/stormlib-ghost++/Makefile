# Created by: <ports@c0decafe.net>
# $FreeBSD$

PORTNAME=	stormlib
PORTVERSION=	6.25
CATEGORIES=	devel archivers
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMESUFFIX=	-ghost++
DISTNAME=	${PROJECTHOST}_${PROJECTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library to read and write MPQ archives

PROJECTHOST=	ghostplusplus
PROJECTVERSION=	17.1

USES=		dos2unix gmake zip
USE_LDCONFIG=	yes

PLIST_FILES=	include/StormLib/StormLib.h \
		include/StormLib/StormPort.h \
		lib/libStorm.so
PLIST_DIRS=	include/StormLib

WRKSRC=		${WRKDIR}/ghost/StormLib/stormlib

post-patch:
	@${REINPLACE_CMD} 's|PREFIX|DESTDIR)$$(&|' ${WRKSRC}/Makefile

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libStorm.so

.include <bsd.port.mk>
