# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-imagemagick

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to ImageMagick

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	IMAGEMAGICK
IMAGEMAGICK_DESC=	Install ImageMagick image proccesing tool
OPTIONS_DEFAULT=	IMAGEMAGICK

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
