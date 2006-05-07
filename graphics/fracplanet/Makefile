# New ports collection makefile for: fracplanet
# Date created:		15 Sep 2005
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	fracplanet
PORTVERSION=	0.2.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	An interactive generator of planets and terrain

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_GL=		yes
USE_QT_VER=	3
USE_X_PREFIX=	yes
MAKE_ENV=	QTDIR="${X11BASE}" QMAKESPEC="${QMAKESPEC}" VERSION_NUMBER="${PORTVERSION}"
WRKSRC=		${WRKDIR}/${PORTNAME}

QMAKE?=		${LOCALBASE}/bin/qmake
QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	fracplanet.htm fracplanet.css

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not build on FreeBSD 4.x"
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|%%PREFIX%%|${PREFIX}|g; s|%%DOCSDIR%%|${DOCSDIR}|g' \
		${WRKSRC}/${PORTNAME}.pro

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
