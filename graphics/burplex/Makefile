# $FreeBSD$

PORTNAME=	burplex
PORTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.burplex.com/ \
		http://www.da3m0n8t3r.com/

MAINTAINER=	waitman@waitman.net
COMMENT=	Preview and select images for batch processing

LICENSE=	BSD

RUN_DEPENDS=	${LOCALBASE}/bin/dcraw:${PORTSDIR}/graphics/dcraw

USE_QT4=	gui qmake_build uic_build moc_build rcc_build \
		imageformats_run
HAS_CONFIGURE=	yes
QMAKE_ARGS=	-recursive PREFIX=${PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN7=		burplex.7
PLIST_FILES=	bin/${PORTNAME}

DESKTOP_ENTRIES=	"burplex" "${COMMENT}" ""  \
			"burplex" "" "false"

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},' \
		${WRKSRC}/mainwindow.cpp

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKE_ARGS} ${QMAKEFLAGS}

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${MANPREFIX}/man/man7
	${INSTALL_MAN} ${WRKSRC}/burplex.7 ${MANPREFIX}/man/man7

.include <bsd.port.mk>
