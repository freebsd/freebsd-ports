# New ports collection makefile for:	libjcode
# Version required:	1.00
# Date created:		8 MAY 1999
# Whom:			Shuichi Tanaka
#
# $FreeBSD$
#

DISTNAME=	libjcode
PKGNAME=	ja-libjcode-1.00
CATEGORIES=	japanese net
MASTER_SITES=	http://keemun.soraneko.com/gtkicq/archives/

MAINTAINER=	stanaka@bb.mbn.or.jp

WRKSRC=		${WRKDIR}/${DISTNAME}-1.00

do-install:
	${INSTALL_DATA}	${WRKSRC}/libjcode.a	${PREFIX}/lib/libjcode.a
	${INSTALL_DATA}	${WRKSRC}/jlib.h	${PREFIX}/include/jlib.h

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
