# ex:ts=8
# New ports collection makefile for:	TenDRA
# Date created:		7 Apr 1998
# Whom:			Robert Nordier <rnordier@iafrica.com>
#
# $FreeBSD$
#

PORTNAME=	TenDRA
PORTVERSION=	4.20030825
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.allbsd.org/pub/TenDRA/snapshots/
DISTNAME=	${PORTNAME:L}-${PORTVERSION:S/4.//}

MAINTAINER=	stefan@fafoe.narf.at
COMMENT=	A portable BSD-licensed compiler suite

ONLY_FOR_ARCHS=	i386

DIST_SUBDIR=	${PKGBASE}
USE_BZIP2=	yes
USE_PERL5_BUILD=	yes
ALL_TARGET=	# nada
MAKE_ARGS=	BIN_CC="${CC}"

TENDRA_OSREL!=	uname -r
TENDRA_ARCH=	${ARCH:S/i386/80x86/}
TENDRA_VER=	5.0.0
TENDRA_PATH=	${TENDRA_VER}/FreeBSD/${TENDRA_OSREL}/${TENDRA_ARCH}
PLIST_SUB+=	TENDRA_VER=${TENDRA_VER} TENDRA_OSREL=${TENDRA_OSREL} \
		TENDRA_PATH=${TENDRA_PATH}

MAN1=		calculus.1 disp.1 lexi.1 pl.1 sid.1 tcc.1 tchk.1 \
		tcpplus.1 tdfc2.1 tld.1 tnc.1 trans.1 tspec.1
MAN5=		tccenv.5

do-configure:
	cd ${WRKSRC} && make PREFIX=${PREFIX} freebsd

# Remove empty directory that is ugly to handle with pkg-plist
post-install:
	${RMDIR} ${PREFIX}/lib/TenDRA/${TENDRA_PATH}/lib/machines/tokens

.include <bsd.port.mk>
