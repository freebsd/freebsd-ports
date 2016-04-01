# Created by: Lukas Maly <Iam@LukasMaly.NET>
# $FreeBSD$

PORTNAME=	gpscorrelate
PORTVERSION=	1.6.1
PORTREVISION=	3
CATEGORIES=	astro geography

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Correlate digital camera photos with GPS data in GPX format

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libgtkmm-2.4.so:x11-toolkits/gtkmm24

USES=		gmake pkgconfig
USE_GNOME=	libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	freefoote

PLIST_FILES=	bin/gpscorrelate bin/gpscorrelate-gui \
		man/man1/gpscorrelate.1.gz man/man1/gpscorrelate-gui.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

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
	${INSTALL_PROGRAM} ${WRKSRC}/gpscorrelate ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gpscorrelate-gui ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/gpscorrelate.1 \
		${STAGEDIR}${MANPREFIX}/man/man1
	${LN} -sf gpscorrelate.1 \
		${STAGEDIR}${MANPREFIX}/man/man1/gpscorrelate-gui.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASES ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
