# $FreeBSD$

PORTREVISION=	1
PKGNAMESUFFIX=	-kmod
MASTERDIR=	${.CURDIR}/../secadm

COMMENT=	HardenedBSD Security Administration - Kernel module

USES=		kmod
KMOD=		yes

USE_GITHUB=	yes
pre-build:
	(cd ${WRKSRC}; make depend)

PLIST=	${.CURDIR}/pkg-plist

NOPIE_PORTS=	yes
.include "${MASTERDIR}/Makefile"
