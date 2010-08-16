# New ports collection makefile for:	fpc-oggvorbis
# Date created: 	2010-04-22
# Whom: 		Christopher Key <cjk32@cam.ac.uk>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	audio lang
PKGNAMESUFFIX=	-oggvorbis

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to ogg & vorbis libraries

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS=	LIBOGG		"Install ogg library"	on \
		LIBVORBIS	"Install vorbis library"	on

.include "${MASTERDIR}/Makefile"
