# Created by: Lukas Maly
# $FreeBSD$

PORTNAME=	gpscorrelate
PORTVERSION=	1.6.1
CATEGORIES=	astro geography
MASTER_SITES=	http://freefoote.dview.net/linux/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A gps file gpx correlate exif tag in photos

LICENSE=	GPLv2

LIB_DEPENDS=	exiv2:${PORTSDIR}/graphics/exiv2 \
		gtkmm-2:${PORTSDIR}/x11-toolkits/gtkmm24

OPTIONS_DEFINE=	DOCS

USE_GNOME=	libxml2
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		gpscorrelate.1
MLINKS=		gpscorrelate.1 gpscorrelate-gui.1
PORTDOCS=	*
PLIST_FILES=	bin/gpscorrelate bin/gpscorrelate-gui

.include <bsd.port.options.mk>

# This port depends on nan(3) added in r174684, Sun Dec 16 21:19:28 2007 UTC.
# There was no __FreeBSD_version bump for this change, so use the nearest one.
.if ${OSVERSION} < 800007
BROKEN=		Does not compile on 7.x: Requires nan(3)
.endif

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
	s|gcc $$(CFLAGS)|$$(CC) $$(CFLAGS) $$(IFLAGS)|' ${WRKSRC}/Makefile


do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gpscorrelate ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/gpscorrelate-gui ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/gpscorrelate.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASES ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${DOCSDIR}/html
.endif

.include <bsd.port.mk>
