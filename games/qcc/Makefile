# New ports collection makefile for:		qcc
# Date created:					October 25th 1996
# Whom:						jfitz@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	qcc
PORTVERSION=	1.01
CATEGORIES=	games devel
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/
DISTNAME=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	The QuakeC compiler, for building custom games of Quake

USE_REINPLACE=	yes

WRKSRC=		${WRKDIR}/send
MAKEFILE=	makefile

post-extract:
		@${REINPLACE_CMD} -E '/^CFLAGS/d; s/cc( -c)? \$$\(C/$$(CC)\1 \$$\(C/' \
			${WRKSRC}/makefile

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/qcc ${PREFIX}/bin
		@${MKDIR} ${PREFIX}/share/qcc/v101qc
		${INSTALL_DATA} ${WRKSRC}/readme.txt ${PREFIX}/share/qcc
		${INSTALL_DATA} ${WRKSRC}/v101qc/* ${PREFIX}/share/qcc/v101qc

.include <bsd.port.mk>
