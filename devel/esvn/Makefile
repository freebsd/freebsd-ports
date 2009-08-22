# New ports collection Makefile for:	esvn
# Date created:        9 August 2004
# Whom:                Andrej Zverev (az@inec.ru)
#
# $FreeBSD$
#

PORTNAME=	esvn
PORTVERSION=	0.6.12
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/eSvn/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	az@FreeBSD.org
COMMENT=	GUI frontend for the Subversion revision system

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
RUN_DEPENDS=	svn:${PORTSDIR}/devel/subversion

ESVN_DIST=	esvn
ESVNPRO=	esvn.pro esvn-diff-wrapper.pro
ESVNDOCS=	html-docs html-docs/common html-docs/common/admon html-docs/common/navig html-docs/images

WRKSRC=		${WRKDIR}/${ESVN_DIST}

HAS_CONFIGURE=	yes
USE_QT_VER=	3
USE_GMAKE=	yes
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--qtdir=${QT_PREFIX}
MAKE_ARGS+=	QTDIR=${QT_PREFIX} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/kde-config)
PLIST_SUB+=	KDE=""
.else
PLIST_SUB+=	KDE="@comment "
.endif

do-configure:
	@for proj in ${ESVNPRO}; do \
	cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ $${proj}; \
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/esvn ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/esvn-diff-wrapper ${PREFIX}/bin
.if exists(${LOCALBASE}/bin/kde-config)
	${MKDIR} ${LOCALBASE}/share/applnk
	${MKDIR} ${LOCALBASE}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${WRKSRC}/eSvn.desktop ${LOCALBASE}/share/applnk
	${INSTALL_DATA} ${WRKSRC}/images/esvn.png ${LOCALBASE}/share/icons/hicolor/48x48/apps
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	for d in ${ESVNDOCS}; do \
	    ${MKDIR} ${DOCSDIR}/$$d; \
	    ${CP} -Rp ${WRKSRC}/$$d/* ${DOCSDIR}/$$d/; \
	done
.endif

.include <bsd.port.post.mk>
