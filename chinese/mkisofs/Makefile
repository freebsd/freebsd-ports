# New ports collection makefile for:	zh-mkisofs
# Date created:			19 Oct 2000
# Whom:				Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mkisofs
PORTVERSION=	1.12b5
PORTREVISION=	1
CATEGORIES=	chinese sysutils
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/
PKGNAMEPREFIX=	zh-

PATCH_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/
PATCHFILES=	mkisofs-1.12b5.big5patch.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Create ISO9660/JOLIET/Rock Ridge filesystems, Big5 compatible

GNU_CONFIGURE=	yes
ALL_TARGET=	World
MAN8=		mkisofs-zh.8
PLIST_FILES=	bin/mkisofs-zh

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs ${PREFIX}/bin/mkisofs-zh
	@${INSTALL_MAN} ${WRKSRC}/mkisofs.8 ${PREFIX}/man/man8/mkisofs-zh.8

.include <bsd.port.mk>
