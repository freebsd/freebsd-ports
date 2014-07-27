# Created by: Timothy Bourke <timbob@bigpond.com>
# $FreeBSD$

PORTNAME=	polyml
PORTVERSION=	5.5.2
CATEGORIES=	lang
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}.${PORTVERSION}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Fast open-source implementation of Standard ML

LICENSE=	LGPL21

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-x --with-system-libffi
USE_GCC=	yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64

USES=	libtool:keepla pkgconfig pathfix

pre-build:
	@${REINPLACE_CMD} "s|ELFXX_R_INFO(_y, _z)    ELF64_R_INFO(_y, _z)|ELFXX_R_INFO(_y, _z)    ELF64_R_INFO((Elf64_Xword)(_y), _z)|g" ${WRKSRC}/libpolyml/elfexport.h

PLIST_FILES=	bin/poly \
		bin/polyc \
		bin/polyimport \
		lib/libpolymain.a \
		lib/libpolymain.la \
		lib/libpolyml.a \
		lib/libpolyml.la \
		libdata/pkgconfig/polyml.pc \
		man/man1/poly.1.gz \
		man/man1/polyc.1.gz \
		man/man1/polyimport.1.gz

.include <bsd.port.mk>
