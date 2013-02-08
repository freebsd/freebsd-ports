# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kardsgt
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Card game suite

USE_QT4=	assistantclient corelib gui network \
		moc_build qmake_build rcc_build uic_build
ALL_TARGET=	qmake release
MAKE_JOBS_UNSAFE=	yes

MAN6=		kardsgt.6

post-patch:
	@${REINPLACE_CMD} -e 's|^QT +=|#QT +=|g' \
		${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -e 's|/usr/share/kardsgt/|${DATADIR}/|g' \
		${WRKSRC}/src/kardsgtinterface.cpp

do-configure:
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/kardsgt ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/doc/kardsgt.6 ${MAN6PREFIX}/man/man6
	@${MKDIR} ${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/src/images/kardsgt.png ${PREFIX}/share/icons
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/doc/*.dcf ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/doc/*.html ${DATADIR}
	@${MKDIR} ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/src/doc/images/*.jpg ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/src/doc/images/*.png ${DATADIR}/images
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CREDITS ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
