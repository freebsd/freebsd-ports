# New ports collection makefile for:   sqsh
# Date created:		14 Jan 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	sqsh
PORTVERSION=	2.1
CATEGORIES=	databases
MASTER_SITES=	http://www.sqsh.org/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tds.0:${PORTSDIR}/databases/freetds

.ifndef WITHOUT_X11
WITH_MOTIF=	yes
CONFIGURE_ARGS+=--with-motif
USE_XLIB=	yes
.else
PKGNAMESUFFIX+=	-nox11
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	SYBASE="${LOCALBASE}"
CONFIGURE_ARGS+=--with-readline

MAN1=	sqsh.1

ALL_TARGET=	build

post-patch:
	${MV} ${WRKSRC}/doc/global.sqshrc ${WRKSRC}/doc/global.sqshrc.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/sqsh ${PREFIX}/bin
	cd ${WRKSRC}/doc && \
		${INSTALL_MAN} ${MAN1} ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/doc/global.sqshrc ${PREFIX}/etc/sqshrc.default

.include <bsd.port.mk>
