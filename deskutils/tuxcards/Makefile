# New ports collection makefile for:	tuxcards
# Date created:				08 Jan 2002
# Whom:			Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tuxcards
PORTVERSION=	1.0.b2.1
CATEGORIES=	deskutils
MASTER_SITES=	http://www.stud.uni-karlsruhe.de/~ut3c/
DISTNAME=	${PORTNAME}-${PORTVERSION:R:S/.b/beta/}_${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}
QTDIR?=		${X11BASE}
USE_QT_VER=	3
USE_REINPLACE=	yes
MAKE_ENV=	QTDIR="${QTDIR}"

post-patch:
	@${REINPLACE_CMD} -e 's|warn_on|warn_on thread|g' ${WRKSRC}/tuxcards.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${X11BASE}/mkspecs/freebsd-g++ tuxcards.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/en/*.* ${DOCSDIR}
.endif
	${CAT} pkg-message

.include <bsd.port.mk>
