# Created by: Lukas Maly
# $FreeBSD$

PORTNAME=	gpscorrelate
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	astro geography
MASTER_SITES=	GH
DIST_SUBDIR=	repacked

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Correlate digital camera photos with GPS data in GPX format

LICENSE=	GPLv2

LIB_DEPENDS=	exiv2:${PORTSDIR}/graphics/exiv2 \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	freefoote
GH_COMMIT=	a36646b

USES=		gmake
USE_GNOME=	libxml2

MAN1=		gpscorrelate.1
MLINKS=		gpscorrelate.1 gpscorrelate-gui.1
PORTDOCS=	*
PLIST_FILES=	bin/gpscorrelate bin/gpscorrelate-gui

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS|#CFLAGS| ; \
		 s|^override CFLAGS|override IFLAGS| ; \
		 s|gtk+-2.0)|gtk+-2.0 exiv2)| ; \
		 s|-I/usr/include/exiv2|| ; \
		 s|-lexiv2|| ; \
		 /^all:/s|gpscorrelate.1|| ; \
		 s|g++ $$(OFLAGS)|$$(CXX) $$(OFLAGS)| ; \
		 s|g++ $$(CFLAGS)|$$(CXX) $$(CXXFLAGS) $$(IFLAGS)| ; \
		 s|gcc $$(CFLAGS)|$$(CC) $$(CFLAGS) $$(IFLAGS)|' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gpscorrelate ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gpscorrelate-gui ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/gpscorrelate.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASES ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
