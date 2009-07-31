# ports collection makefile for:	qsstv
# Date created:		28 August 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	qsstv
PORTVERSION=	6.0a
PORTREVISION=	4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://users.telenet.be/on4qz/snapshots/download/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio SSTV/FAX reception program for unix

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--qtdir=${QT_PREFIX}
MAKE_ARGS+=	QTDIR=${QT_PREFIX} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		DESTDIR="" TARGET="qsstv" DOCSDIR="${DOCSDIR}"

post-patch:
	${REINPLACE_CMD} -e 's|%%DOCSDIR%%|${DOCSDIR}|g' \
	${WRKSRC}/configdialog.cpp

do-configure:
	cd ${WRKSRC}; \
	${SETENV} ${CONFIGURE_ENV} ${LOCALBASE}/bin/qmake -spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ ${PORTNAME}.pro; \

do-install:
	${INSTALL_PROGRAM} -m 755 ${WRKSRC}/qsstv ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
