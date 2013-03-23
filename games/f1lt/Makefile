# Created by: Jason Helfman <jgh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	f1lt
PORTVERSION=	2.0.0
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Unofficial Formula 1 live timing application

LICENSE=	GPLv3

OPTIONS_DEFINE=	DOCS

USE_QT4=	gui network moc_build qmake_build rcc_build uic_build
WRKSRC=	${PORTNAME}-${PORTVERSION}

HAS_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/F1LT \
		share/F1LT/season.dat \
		share/F1LT/trackdata.dat \
		share/F1LT/trackrecords.dat
PLIST_DIRSTRY=	share/F1LT
PORTDOCS=	CHANGELOG

.include <bsd.port.pre.mk>

post-patch-script:
	@${REINPLACE_CMD} -e 's|PREFIX = /opt|PREFIX = /usr/local|g' \
		${WRKSRC}/F1LT.pro
	@${REINPLACE_CMD} -e 's|$$PREFIX/share/|$$PREFIX/share/$$$$TARGET/|g' \
		${WRKSRC}/F1LT.pro
	@${REINPLACE_CMD} -e 's|PREFIX = /usr/local/$$$$TARGET|PREFIX = /usr/local/|g' \
		${WRKSRC}/F1LT.pro
	@${REINPLACE_CMD} -e 's|target.path = $$PREFIX/bin/|target.path = /usr/local/bin/|g' \
		${WRKSRC}/F1LT.pro
.if ${ARCH} == "i386"
	@${REINPLACE_CMD} -e 's|999999999998|1000000|g' \
		${WRKSRC}/src/tools/laptimecomparisondialog.cpp
.endif

.include <bsd.port.options.mk>

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKEFLAGS} PREFIX=${PREFIX} F1LT.pro

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}
.endif
	@${CHMOD} 0664 ${PREFIX}/share/F1LT/trackrecords.dat

.include <bsd.port.post.mk>
