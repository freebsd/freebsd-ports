# New ports collection makefile for:	m6811-binutils
# Date created:		Fri Feb  4 12:27:19 PST 2000
# Whom:			jburkhol@home.com
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	2.11.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	binutils
PKGNAMEPREFIX=	m6811-

PATCH_SITES=	http://stephane.carrez.free.fr/snapshots/
PATCHFILES=	${PORTNAME}-${PORTVERSION}-m68hc1x-20020203.diffs.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The binutils-2.9.1 cross-toolchain for the 6811

NOT_FOR_ARCHS=	amd64
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --target=m6811-elf	\
			--program-prefix=m6811-elf-

MAN1=		m6811-elf-ar.1 m6811-elf-nlmconv.1 m6811-elf-c++filt.1	\
		m6811-elf-nm.1 m6811-elf-objdump.1 m6811-elf-ranlib.1	\
		m6811-elf-size.1 m6811-elf-strings.1 m6811-elf-strip.1	\
		m6811-elf-objcopy.1 m6811-elf-addr2line.1		\
		m6811-elf-as.1 m6811-elf-ld.1 \
		m6811-elf-dlltool.1 m6811-elf-readelf.1 m6811-elf-windres.1

.include <bsd.port.mk>
