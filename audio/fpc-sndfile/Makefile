# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	audio lang
PKGNAMESUFFIX=	-sndfile

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal Interface to sndfile library

USE_FPC=	yes
NO_STAGE=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	LIBSNDFILE
LIBSNDFILE_DESC=	Install sndfile library
OPTIONS_DEFAULT=	LIBSNDFILE

.include "${MASTERDIR}/Makefile"
