# New ports collection makefile for: mingw-bin-msvcrt
# Date created:		6 June 2000
# Whom:			Toshihiro Inoue <tino@pa2.so-net.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	bin-msvcrt
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mingw
PKGNAMEPREFIX=	mingw-
DISTFILES=	mingw-runtime-${PORTVERSION}${EXTRACT_SUFX} \
		w32api-${PORTVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	mingw

MAINTAINER=	doc@hisio.safenet.pl

NO_MTREE=	yes
NO_WRKSUBDIR=	yes

post-extract:
	@${CP} ${FILESDIR}/Makefile ${WRKDIR}

.include <bsd.port.mk>
