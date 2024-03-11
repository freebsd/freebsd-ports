PORTNAME=	ghidra
PORTVERSION=	${GHIDRA_VERSION}
PORTREVISION=	0
CATEGORIES=	devel

MAINTAINER=	zyj20@cl.cam.ac.uk
COMMENT=	Meta-port for the default version of the Ghidra SRE framework
WWW=		https://ghidra-sre.org/
DESCR=		${.CURDIR}/../ghidra/pkg-descr

USES=		metaport

RUN_DEPENDS=	${LOCALBASE}/bin/ghidra-cheri:devel/ghidra-cheri

.include "${.CURDIR}/../ghidra-cheri/Makefile.snapshot"
.include <bsd.port.mk>
