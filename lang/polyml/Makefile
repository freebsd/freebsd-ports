# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	polyml
PORTVERSION=	5.5.2
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}.${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Fast open-source implementation of Standard ML

LICENSE=	LGPL21

LIB_DEPENDS=	libffi.so:${PORTSDIR}/devel/libffi

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-system-libffi
USES=		libtool pkgconfig pathfix
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	MOTIF

.include <bsd.port.options.mk>

MOTIF_CONFIGURE_WITH=	x
MOTIF_USE=		motif

pre-build:
	@${REINPLACE_CMD} "s|ELFXX_R_INFO(_y, _z)    ELF64_R_INFO(_y, _z)|ELFXX_R_INFO(_y, _z)    ELF64_R_INFO((Elf64_Xword)(_y), _z)|g" ${WRKSRC}/libpolyml/elfexport.h

.include <bsd.port.mk>
