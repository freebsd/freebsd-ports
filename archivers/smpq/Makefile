PORTNAME=	smpq
DISTVERSION=	1.6
CATEGORIES=	archivers devel games
MASTER_SITES=	https://launchpad.net/${PORTNAME}/trunk/${PORTVERSION}/+download/
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	agh@riseup.net
COMMENT=	StormLib MPQ archiving utility
WWW=		https://launchpad.net/smpq/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	stormlib>0:archivers/stormlib
LIB_DEPENDS=	libstorm.so:archivers/stormlib

USES=		cmake
CMAKE_ON=	WITH_CMD
CMAKE_OFF=	WITH_KDE

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
