# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	f1lt
PORTVERSION=	2.1.1
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE \
		LOCAL/jgh/games/${PORTNAME}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Unofficial Formula 1 live timing application

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

USE_QT4=	gui network moc_build qmake_build rcc_build uic_build
WRKSRC=	${WRKDIR}/${DISTNAME:S|-src||}

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/F1LT \
		bin/f1lt \
		share/f1lt/season.dat \
		share/f1lt/trackdata.dat \
		share/f1lt/trackrecords.dat
PLIST_DIRSTRY=	share/f1lt
PORTDOCS=	CHANGELOG

.include <bsd.port.options.mk>

post-patch-script:
	@${REINPLACE_CMD} -e 's|PREFIX = /opt/$$$$TARGET|PREFIX = ${PREFIX}|g' \
		${WRKSRC}/F1LT.pro
	@${REINPLACE_CMD} -e 's|SHARE=$$$$PREFIX/share|SHARE=$$$$PREFIX/share/${PORTNAME}|g' \
		${WRKSRC}/F1LT.pro
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} -e 's|999999999998|1000000|g' \
		${WRKSRC}/src/tools/laptimecomparisondialog.cpp
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX} F1LT.pro

post-build-script:
	@${REINPLACE_CMD} -e 's|-$$(INSTALL_FILE)|${INSTALL} -o ${SHAREOWN} -g ${SHAREGRP} -m 644|g' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|-$$(INSTALL_PROGRAM)|${INSTALL} -s -o ${SHAREOWN} -g ${SHAREGRP} -m 755|g' \
		${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
.endif
	@${LN} -s ${PREFIX}/bin/F1LT ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
