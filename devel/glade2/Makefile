# New ports collection makefile for:	glade
# Date created:		29 June 1998
# Whom:			Dom Mitchell <dom@myrddin.demon.co.uk>
#
# $FreeBSD$
#

PORTNAME=	glade
PORTVERSION=	0.5.7
CATEGORIES=	devel
MASTER_SITES=   http://glade.pn.org/

MAINTAINER=     ade@FreeBSD.org

.if defined(WITH_GNOME)
LIB_DEPENDS=	gnome.3:${PORTSDIR}/x11/gnomelibs
PLIST_GNOME=	${PKGDIR}/PLIST.gnome
.else
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12
CONFIGURE_ARGS=	--disable-gnome
.endif

PLIST=		${WRKDIR}/PLIST

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

FETCH_BEFORE_ARGS=	-b

USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/libs"

.if !defined(WITH_GNOME)
pre-extract:
	@${ECHO} "You can add hooks for GNOME by defining WITH_GNOME"
.endif

post-patch:
.if !defined(WITH_GNOME)
	@cd ${WRKSRC} && ${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-nognome
.endif

pre-install:
	@sort -r -o ${PLIST} ${PLIST_GNOME} ${PKGDIR}/PLIST

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/TODO ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/developer.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/file_format.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/generic.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/manual.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/notes.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/portability.txt ${PREFIX}/share/doc/glade
	${INSTALL_MAN} ${WRKSRC}/doc/source_code.txt ${PREFIX}/share/doc/glade
.endif

.include <bsd.port.mk>
