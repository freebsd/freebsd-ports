# ex:ts=8
# New ports collection makefile for:	fractorama
# Date created:			Apr 15, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fractorama
PORTVERSION=	1.5.1E
CATEGORIES=	graphics
MASTER_SITES=	http://fractorama.com/
DISTNAME=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

USE_BISON=	yes
USE_QT_VER=	2
WRKSRC=		${WRKDIR}/${DISTNAME}/src
USE_GMAKE=	yes
MAKE_ENV=	QTCPPFLAGS="${QTCPPFLAGS}" QTCFGLIBS="${QTCFGLIBS}" MOC=${MOC}
ALL_TARGET=	release

post-patch:
	@find ${WRKSRC} -name Makefile | xargs \
		${PERL} -pi -e "s,OPTIMIZE := -O2,OPTIMIZE := ${CFLAGS},g"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../fractorama.exe ${PREFIX}/bin/fractorama
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/fractorama
	${CP} -R ${WRKSRC}/../examples/* ${PREFIX}/share/examples/fractorama
	${MKDIR} ${PREFIX}/share/doc/fractorama
	${CP} -R ${WRKSRC}/../doc/* ${PREFIX}/share/doc/fractorama
.endif

.include <bsd.port.mk>
