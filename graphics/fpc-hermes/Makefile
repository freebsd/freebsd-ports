# Created by: Christopher Key <cjk32@cam.ac.uk>
# $FreeBSD$

PORTREVISION=	0
CATEGORIES=	graphics lang
PKGNAMESUFFIX=	-hermes

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free Pascal hermes unit

USE_FPC=	yes

MASTERDIR=	${.CURDIR}/../../lang/fpc
WRKUNITDIR=	${FPCSRCDIR}/packages/${PKGNAMESUFFIX:S/-//}
EXTRACTUNITDIR+=	${WRKUNITDIR}

OPTIONS_DEFINE=	HERMES
HERMES_DESC=	Install hermes graphics library
OPTIONS_DEFAULT=	HERMES

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
