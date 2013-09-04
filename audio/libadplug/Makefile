# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	libadplug
PORTVERSION=	2.2.1
CATEGORIES=	audio
MASTER_SITES=	SF/adplug/AdPlug%20core%20library/${PORTVERSION}
DISTNAME=	adplug-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AdLib emulator library supporting many formats

LICENSE=	GPLv2

LIB_DEPENDS=	binio:${PORTSDIR}/devel/libbinio

USES=		pkgconfig
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_CSTD=	gnu89

CPPFLAGS+=	-I${LOCALBASE}/include

INFO=		libadplug
MAN1=		adplugdb.1

post-patch:
	@${REINPLACE_CMD} -E 's#<(binfile.h|binio.h|binstr.h)>#<libbinio/\1>#' \
		${WRKSRC}/adplugdb/adplugdb.cpp \
		${WRKSRC}/src/adplug.cpp \
		${WRKSRC}/src/fprovide.cpp \
		${WRKSRC}/src/database.cpp \
		${WRKSRC}/src/rix.cpp \
		${WRKSRC}/src/fprovide.h \
		${WRKSRC}/src/database.h \
		${WRKSRC}/src/fprovide.cpp \
		${WRKSRC}/src/database.cpp \
		${WRKSRC}/src/dmo.cpp
	@${REINPLACE_CMD} -e 's|^\(pkgconfigdir\ =\).*|\1 $$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/Makefile.am
	@${REINPLACE_CMD} -e 's/-lstdc++//g' ${WRKSRC}/configure

.include <bsd.port.mk>
