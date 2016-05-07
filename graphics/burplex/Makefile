# $FreeBSD$

PORTNAME=	burplex
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.burplex.com/ \
		http://www.da3m0n8t3r.com/

MAINTAINER=	waitman@waitman.net
COMMENT=	Preview and select images for batch processing

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${LOCALBASE}/bin/dcraw:graphics/dcraw

USES=		qmake
USE_QT4=	gui uic_build moc_build rcc_build \
		imageformats_run
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		man/man7/burplex.7.gz

DESKTOP_ENTRIES=	"burplex" "${COMMENT}" ""  \
			"burplex" "" "true"

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' \
		${WRKSRC}/mainwindow.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/burplex.7 ${STAGEDIR}${MANPREFIX}/man/man7

.include <bsd.port.mk>
