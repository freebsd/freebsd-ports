# New ports collection makefile for:	Yasou picture book - JIS X 4081 version
# Date created:        	2004.11.08
# Whom:			Hideyuki KURASHINA <rushani@FreeBSD.org>
# Based on:		Satoshi Taoka's roget-fpw
#
# $FreeBSD$
#

PORTNAME=	yasou-fpw
PORTVERSION=	1.0.b0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.jp/edict/fpw/dist/yasou/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.b0/beta0/}

MAINTAINER=	rushani@FreeBSD.org
COMMENT=	Yasou picture book (EPWING V1 format) by SAS

NO_CDROM=	"No commercial use, and no redistribution allowed with fee except media and/or shipping cost"

USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/yasou
EXTRACT_BEFORE_ARGS=	-qL

do-install:
	${MKDIR} ${PREFIX}/share/dict/yasou-fpw/yasou/data
	${INSTALL_DATA} ${WRKSRC}/yasou/data/honmon ${PREFIX}/share/dict/yasou-fpw/yasou/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/yasou-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in readme.fpw yasoufpw.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
