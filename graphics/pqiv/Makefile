# New ports collection makefile for:	graphics/pqiv
# Date created:				March 28 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	pqiv
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.pberndt.com/raw//Programme/Linux/pqiv/_download/ \
		http://www.carpetsmoker.net/distfiles/ \
		http://www.xs4all.nl/~tournoij/distfiles/ \
		http://www.rwxrwxrwx.net/distfiles/
EXTRACT_SUFX=	.tbz

MAINTAINER=	carpetsmoker@rwxrwxrwx.net
COMMENT=	Pretty Quick Image Viewer

USE_BZIP2=	yes
USE_GNOME=	gtk20 glib20 pango pkgconfig
CFLAGS+=	-DNO_INOTIFY
PLIST_FILES=	bin/pqiv
PORTDOCS=	README
MAN1=		pqiv.1
MANCOMPRESSED=	no

OPTIONS=	SORTING		"Enable sorting of loaded files" on \
		COMPOSITE	"Enable support for transparent windows" on \
		FADING		"Enable support for fading images" on \
		COMMANDS	"Enable support for external command execution" on \
		CONFIG		"Enable support for a configuration file" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SORTING)
CFLAGS+=	-DNO_SORTING
SORTFILE=	# Empty
.else
SORTFILE=	${WRKSRC}/lib/strnatcmp.c
.endif
.if defined(WITHOUT_COMPOSITE)
CFLAGS+=	-DNO_COMPOSITING
.endif
.if defined(WITHOUT_FADING)
CFLAGS+=	-DNO_FADING
.endif
.if defined(WITHOUT_COMMANDS)
CFLAGS+=	-DNO_COMMANDS
.endif
.if defined(WITHOUT_CONFIG)
CFLAGS+=	-DNO_CONFIG_FILE
.endif

do-build:
	${CC} ${CFLAGS} `${pkgconfig_DETECT} --libs --cflags gtk+-2.0 gthread-2.0 pango glib-2.0` \
		${SORTFILE} ${WRKSRC}/pqiv.c -o ${WRKSRC}/pqiv
	@${REINPLACE_CMD} 's|$$PACKAGE_VERSION|${PORTVERSION}|' \
		${WRKSRC}/pqiv.1.template

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pqiv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pqiv.1.template ${MAN1PREFIX}/man/man1/pqiv.1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
