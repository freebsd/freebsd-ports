# New ports collection makefile for:		qcc
# Date created:					October 25th 1996
# Whom:						jfitz@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	qcc
PORTVERSION=	1.01
CATEGORIES=	games devel
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE}
MASTER_SITE_SUBDIR=	source
DISTNAME=	${PORTNAME}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	The QuakeC compiler, for building custom games of Quake

WRKSRC=		${WRKDIR}/send
MAKEFILE=	makefile

PLIST_FILES=	bin/qcc
PORTDOCS=	readme.txt

post-extract:
		@${REINPLACE_CMD} -E '/^CFLAGS/d; s/cc( -c)? \$$\(C/$$(CC)\1 \$$\(C/' \
			${WRKSRC}/makefile

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/qcc ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		${MKDIR} ${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}
.endif

.include "${.CURDIR}/../quake-source/Makefile.include"

.include <bsd.port.mk>
