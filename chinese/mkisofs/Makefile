# New ports collection makefile for:	zh-mkisofs
# Date created:			19 Oct 2000
# Whom:				Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mkisofs
PORTVERSION=	1.12b5
CATEGORIES=	chinese sysutils
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/

PATCH_SITES=	ftp://freebsd.sinica.edu.tw/pub/keith/
PATCHFILES=	mkisofs-1.12b5.big5patch.gz

MAINTAINER=	keith@FreeBSD.org

GNU_CONFIGURE=	yes
ALL_TARGET=	World
MAN8=		mkisofs.8 isoinfo.8

pre-configure:
	${PERL} -pi.orig -e 's:prefix = /usr/local:prefix = ${PREFIX}:' \
		${WRKSRC}/diag/Makefile.in

post-build:
	cd ${WRKSRC}/diag && make

post-install:
	cd ${WRKSRC}/diag && make install

.include <bsd.port.mk>
