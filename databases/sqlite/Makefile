# ex:ts=8
# New ports collection makefile for:	sqlite
# Date created:			Feb 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlite
PORTVERSION=	1.0.27
CATEGORIES=	databases
MASTER_SITES=	http://www.hwaci.com/sw/sqlite/
DISTNAME=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../sqlite/configure
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" CFLAGS="-L${LOCALBASE}/lib"

WRKSRC=		${WRKDIR}/bld

post-extract:
	@${MKDIR} ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sqlite ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libsqlite.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/sqlite.h ${PREFIX}/include

.include <bsd.port.mk>
