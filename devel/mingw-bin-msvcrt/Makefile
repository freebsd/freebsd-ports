# New ports collection makefile for: mingw-bin-msvcrt
# Date created:		6 June 2000
# Whom:			Toshihiro Inoue <tino@pa2.so-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	bin-msvcrt
PORTVERSION=	2000.03.27
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.xraylith.wisc.edu/pub/khan/gnu-win32/mingw32/runtime/
PKGNAMEPREFIX=	mingw-
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	tino@pa2.so-net.ne.jp

NO_MTREE=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>
