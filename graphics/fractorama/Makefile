# ex:ts=8
# New ports collection makefile for:	fractorama
# Date created:			Apr 15, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fractorama
PORTVERSION=	1.6.4
CATEGORIES=	graphics
MASTER_SITES=	http://fractorama.com/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Fractal generation program

USE_BISON=	yes
USE_QT_VER=	3
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
MAKE_ENV=	QTCPPFLAGS="${QTCPPFLAGS}" QTCFGLIBS="${QTCFGLIBS}" MOC=${MOC}
ALL_TARGET=	release
USE_REINPLACE=	yes

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s,OPTIMIZE := -O2,OPTIMIZE := ${CFLAGS},g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../fractorama.exe ${PREFIX}/bin/fractorama
.if !defined(NOPORTDOCS)
	${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/../examples/* ${EXAMPLESDIR}
	${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/../doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
