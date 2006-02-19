# New ports collection makefile for:	libadplug
# Date created:				10 August 2004
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	libadplug
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	adplug
DISTNAME=	adplug-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	AdLib emulator library supporting many formats

LIB_DEPENDS=	binio.1:${PORTSDIR}/devel/libbinio

INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=	libtool:15
USE_GCC=	3.4+

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS} ${CPPFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

MAN1=		adplugdb.1

post-patch:
	@${REINPLACE_CMD} -e 's|\(binio\.h\)|libbinio/\1|' \
		${WRKSRC}/src/database.cpp \
		${WRKSRC}/src/database.h \
		${WRKSRC}/src/fprovide.cpp \
		${WRKSRC}/src/fprovide.h
	@${REINPLACE_CMD} -e 's|\(binfile\.h\)|libbinio/\1|' \
		${WRKSRC}/adplugdb/adplugdb.cpp \
		${WRKSRC}/src/adplug.cpp \
		${WRKSRC}/src/database.cpp \
		${WRKSRC}/src/fprovide.cpp
	@${REINPLACE_CMD} -e 's|\(binstr\.h\)|libbinio/\1|' \
		${WRKSRC}/src/dmo.cpp
	@${REINPLACE_CMD} -e 's|^\(SUBDIRS\ =\).*|\1 src adplugdb test|' \
		${WRKSRC}/Makefile.in

post-install:
	${MKDIR} ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/adplugdb.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
