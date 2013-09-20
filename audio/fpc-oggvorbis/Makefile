# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	audio lang
PKGNAMESUFFIX=	-oggvorbis

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to ogg & vorbis libraries

USE_FPC=	yes
NO_STAGE=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBOGG LIBVORBIS 
LIBOGG_DESC=	Install ogg library
LIBVORBIS_DESC=	Install vorbis library
OPTIONS_DEFAULT=	LIBOGG LIBVORBIS

.include "${MASTERDIR}/Makefile"
