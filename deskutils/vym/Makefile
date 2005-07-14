# New ports collection makefile for:	vym
# Date created:				17 Oct 2004
# Whom:			Gerrit Beine <tux@pinguru.net>
#
# $FreeBSD$
#

PORTNAME=	vym
PORTVERSION=	1.6.0
CATEGORIES=	deskutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	tux@pinguru.net
COMMENT=	VYM  (View Your Mind) is a tool to generate and manipulate maps

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"

.include <bsd.port.pre.mk>

# Add this condititonal while people might still have old versions
# of qmake, living in X11BASE, installed. This should go away eventually.

.if exists(${X11BASE}/share/qt/mkspecs/freebsd-g++)
QMAKESPEC=	${X11BASE}/share/qt/mkspecs/freebsd-g++
.else
QMAKESPEC=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${QMAKESPEC} vym.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/scripts ${DATADIR}
	@${CP} -R ${WRKSRC}/styles ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
	@${CP} -R ${WRKSRC}/demos/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
