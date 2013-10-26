# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=		psptoolchain
PORTVERSION=		20111215
PORTREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		# none
DISTFILES=		# none

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain meta port

RUN_DEPENDS=		psp-gdb:${PORTSDIR}/devel/psptoolchain-gdb \
			psp-gcc:${PORTSDIR}/devel/psptoolchain-gcc-stage2 \
			psp-g++:${PORTSDIR}/devel/psptoolchain-gcc-stage2 \
			psp-ar:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-as:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-c++filt:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-ld:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-nm:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-objcopy:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-objdump:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-ranlib:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-readelf:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-size:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-strings:${PORTSDIR}/devel/psptoolchain-binutils \
			psp-strip:${PORTSDIR}/devel/psptoolchain-binutils

NO_WRKSUBDIR=		YES
NO_BUILD=		YES
NO_FETCH=		YES

NO_STAGE=	yes
do-install:

.include <bsd.port.mk>
