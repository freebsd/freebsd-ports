# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

CATEGORIES=	audio lang
PKGNAMESUFFIX=	-oggvorbis

MAINTAINER=	freebsd-fpc@FreeBSD.org
COMMENT=	Free Pascal interface to ogg & vorbis libraries

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBOGG LIBVORBIS
LIBOGG_DESC=	Install ogg library
LIBVORBIS_DESC=	Install vorbis library
OPTIONS_DEFAULT=	LIBOGG LIBVORBIS

LIBOGG_LIB_DEPENDS=	libogg.so:audio/libogg
LIBVORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis

.include "${MASTERDIR}/Makefile"
