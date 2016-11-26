# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	polyml
PORTVERSION=	5.6
DISTVERSIONPREFIX=	v
CATEGORIES=	lang
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Fast open-source implementation of Standard ML

LICENSE=	LGPL21

LIB_DEPENDS=	libffi.so:devel/libffi

ONLY_FOR_ARCHS=	i386 amd64

USE_GITHUB=	yes

USES=		libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-libffi --enable-shared
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	MOTIF

MOTIF_CONFIGURE_WITH=	x
MOTIF_USE=		motif

post-patch:
	@${REINPLACE_CMD} -e 's|-lstdc++ ||' ${WRKSRC}/configure
	@${REINPLACE_CMD} "s|ELFXX_R_INFO(_y, _z)    ELF64_R_INFO(_y, _z)|ELFXX_R_INFO(_y, _z)    ELF64_R_INFO((Elf64_Xword)(_y), _z)|g" ${WRKSRC}/libpolyml/elfexport.h

.include <bsd.port.mk>
