PORTNAME=	qemu
PORTVERSION=	0.d${SNAPDATE}
PORTREVISION=	0
CATEGORIES=	emulators

MAINTAINER=	konrad.witaszczyk@cl.cam.ac.uk
COMMENT=	Meta-port for the default version of the QEMU CPU Emulator
WWW=		https://cheribsd.org/
DESCR=		${.CURDIR}/../qemu/pkg-descr

USES=		metaport

RUN_DEPENDS=	${LOCALBASE}/bin/qemu-system-morello:emulators/qemu-cheri

.include "${.CURDIR}/../qemu-cheri/Makefile.snapshot"
.include <bsd.port.mk>
