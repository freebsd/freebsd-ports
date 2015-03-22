# Created by: Toshihiko SHIMOKAWA <toshi@tea.forus.or.jp> & ELISA Font Project
# $FreeBSD$

PORTNAME=	elisa8x8
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	japanese x11-fonts
MASTER_SITES=	http://www.bsdbbq.org/~toshi/distfiles/
DISTNAME=	elisat10

MAINTAINER=	toshi@tea.forus.or.jp
COMMENT=	X11 8-dot Kanji font 'elisa font'

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf

USES=		fonts
NO_WRKSUBDIR=	yes

BDFTOPCF_CMD=	${PREFIX}/bin/bdftopcf
MYPORTDOCS=	elisa100.doc elisat10.doc elisat10.html

OPTIONS_DEFINE=	DOCS

do-build:
	@(cd ${WRKDIR}; \
	${BDFTOPCF_CMD} elisat10.bdf   | ${GZIP_CMD} -c > elisat10.pcf.gz ;\
	${BDFTOPCF_CMD} jpnhn4-jis.bdf | ${GZIP_CMD} -c > jpnhn4-jis.pcf.gz ;\
	${BDFTOPCF_CMD} jpnhn4-iso.bdf | ${GZIP_CMD} -c > jpnhn4-iso.pcf.gz ;\
	)

do-install:
	@${MKDIR} ${STAGEDIR}${FONTSDIR}
	(cd ${WRKSRC} ;\
	${INSTALL_DATA} elisat10.pcf.gz ${STAGEDIR}${FONTSDIR} ; \
	${INSTALL_DATA} jpnhn4-jis.pcf.gz ${STAGEDIR}${FONTSDIR} ; \
	${INSTALL_DATA} jpnhn4-iso.pcf.gz ${STAGEDIR}${FONTSDIR} ; \
	)

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${MYPORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
