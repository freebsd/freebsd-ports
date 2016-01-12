# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kardsgt
PORTVERSION=	0.7.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Card game suite

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		qmake
USE_QT4=	assistantclient corelib gui network \
		moc_build rcc_build uic_build
ALL_TARGET=	qmake release
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|^QT +=|#QT +=|g' \
		${WRKSRC}/src/src.pro
	@${REINPLACE_CMD} -e 's|/usr/share/kardsgt/|${DATADIR}/|g' \
		${WRKSRC}/src/kardsgtinterface.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/release/kardsgt ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/src/doc/kardsgt.6 ${STAGEDIR}${MAN6PREFIX}/man/man6
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons
	${INSTALL_DATA} ${WRKSRC}/src/images/kardsgt.png ${STAGEDIR}${PREFIX}/share/icons
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/doc/*.dcf ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/src/doc/*.html ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/src/doc/images/*.jpg ${STAGEDIR}${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/src/doc/images/*.png ${STAGEDIR}${DATADIR}/images

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in CREDITS ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
