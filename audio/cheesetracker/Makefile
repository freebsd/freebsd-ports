# ex:ts=8
# Ports collection makefile for:	cheesetracker
# Date created:			Jan 31, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cheesetracker
PORTVERSION=	0.9.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cheesetronic

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Impulse Tracker clone

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa
LIB_DEPENDS=	sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"

post-patch:
	@${CP} ${FILESDIR}/cheesetracker.pro ${WRKSRC}

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ cheesetracker.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cheesetracker ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.it ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.xm ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
