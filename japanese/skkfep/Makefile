# New ports collection Makefile for:	skkfep
# Date created:		22 Jul 1998
# Whom:			Yusuke Nawano <azuki@azkey.org>
#
# $FreeBSD$
#

PORTNAME=	skkfep
PORTVERSION=	0.85
CATEGORIES=	japanese
MASTER_SITES=	ftp://ftp.azkey.org/pub/misc/skkfep/
DISTNAME=	${PORTNAME}${PORTVERSION}

PATCH_SITES=	ftp://ftp.azkey.org/pub/misc/skkfep/
PATCHFILES=	skkfep111.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	azuki@azkey.org

RUN_DEPENDS=	${LOCALBASE}/libexec/skkserv:${PORTSDIR}/japanese/skk

NO_WRKSUBDIR=	yes

MAN1=		skkfep.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skkfep ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/escmode ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/resetsize ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/skkfep.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
