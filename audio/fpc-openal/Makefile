# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	audio lang
PKGNAMESUFFIX=	-openal

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal interface to openal library

USE_FPC=	yes
NO_STAGE=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	OPENAL
OPENAL_DESC=	Install openal library
OPTIONS_DEFAULT=	OPENAL

OPENAL_USES=	openal:soft

.include "${MASTERDIR}/Makefile"
