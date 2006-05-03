# ports collection makefile for:	qsstv
# Date created:		28 August 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	qsstv
PORTVERSION=	6.0a
CATEGORIES=	comms hamradio
MASTER_SITES=	http://users.telenet.be/on4qz/snapshots/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@db.net
COMMENT=	Amateur Radio SSTV/FAX reception program for unix

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_QT_VER=	3
CONFIGURE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++
CONFIGURE_ARGS=	--qtdir=${X11BASE}
MAKE_ARGS+=	QTDIR=${X11BASE} \
		QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		DESTDIR="" TARGET="qsstv" DOCSDIR="${DOCSDIR}"

.include <bsd.port.pre.mk>

post-patch:
.if ${OSVERSION} < 500000
	@${FIND} ${WRKSRC} -name '*.cpp' | ${XARGS} ${REINPLACE_CMD} -e 's|)round(|)rint(|g ; s|) round(|)rint(|g ; s|(round)|(rint)|'
.endif

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

.include <bsd.port.post.mk>
