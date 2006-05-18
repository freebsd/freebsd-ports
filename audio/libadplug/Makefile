# New ports collection makefile for:	libadplug
# Date created:				10 August 2004
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	libadplug
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	adplug
DISTNAME=	adplug-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AdLib emulator library supporting many formats

LIB_DEPENDS=	binio.1:${PORTSDIR}/devel/libbinio

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GCC=	3.4+
USE_GNOME=	pkgconfig

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

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
	@${REINPLACE_CMD} -e 's|^\(pkgconfigdir\ =.*\)|\1 $$(prefix)/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in \
		${WRKSRC}/Makefile.am

.include <bsd.port.mk>
