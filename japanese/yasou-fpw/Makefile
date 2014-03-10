# Created by: Hideyuki KURASHINA <rushani@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yasou-fpw
PORTVERSION=	1.0.b0
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.jp/edict/fpw/dist/yasou/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.b0/beta0/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yasou picture book (EPWING V1 format) by SAS

NO_CDROM=	No commercial use, and no redistribution allowed with fee except media and/or shipping cost

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/yasou
EXTRACT_BEFORE_ARGS=	-qL

NO_STAGE=	yes
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
