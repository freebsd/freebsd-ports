PORTNAME=	libgdsii
DISTVERSION=	0.21
CATEGORIES=	cad
MASTER_SITES=	https://github.com/HomerReid/libGDSII/releases/download/v${DISTVERSION}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ library and command-line utility for reading GDSII geometry files
WWW=		https://github.com/HomerReid/libGDSII

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/GDSIIConvert \
		include/libGDSII.h \
		lib/libGDSII.a \
		lib/libGDSII.so \
		lib/libGDSII.so.0 \
		lib/libGDSII.so.0.0.0 \
		share/libGDSII/examples/bend-flux/bend-flux.gds

.include <bsd.port.mk>
