# New ports collection Makefile for:	esvn
# Date created:        9 August 2004
# Whom:                Andrej Zverev (az@inec.ru)
#
# $FreeBSD$
#

PORTNAME=	esvn
PORTVERSION=	0.5.5
CATEGORIES=	devel
MASTER_SITES=	http://esvn.umputun.com/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	az@inec.ru
COMMENT=	GUI frontend for the Subversion revision system

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion

ESVN_DIST=	esvn
ESVNPRO=	esvn.pro esvn-diff-wrapper.pro

WRKSRC=		${WRKDIR}/${ESVN_DIST}

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--qtdir=${X11BASE}
MAKE_ARGS+=	QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

PORTDOCS=	AUTHORS ChangeLog README VERSION

.include <bsd.port.pre.mk>

do-configure:
	@for proj in ${ESVNPRO}; do \
	cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ $${proj}; \
	done

post-configure:
.if exists(/boot/modules/nvidia.ko) && ${OSVERSION} > 502122
	${REINPLACE_CMD} -e 's#-lpthread#-lc_r#' ${WRKSRC}/esvn.mak ${WRKSRC}/esvn-diff-wrapper.mak
.endif

post-build:
	${REINPLACE_CMD} -e 's#esvn.png#${PREFIX}/share/pixmaps/esvn.png#' ${WRKSRC}/eSvn.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esvn ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/esvn-diff-wrapper ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/applications ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/eSvn.desktop ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/esvn.png ${PREFIX}/share/pixmaps

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for f in ${PORTDOCS}; do \
	    ${INSTALL_DATA} ${WRKSRC}/$$f ${DOCSDIR}; \
	done
.endif				  

.include <bsd.port.post.mk>
