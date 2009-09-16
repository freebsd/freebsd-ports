# New ports collection makefile for:	graphics/pqiv
# Date created:				March 28 2008
# Whom:					Martin Tournoij <carpetsmoker@xs4all.nl>
#
# $FreeBSD$
#

PORTNAME=	pqiv
PORTVERSION=	0.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.pberndt.com/raw/Programme/Linux/pqiv/_download/
EXTRACT_SUFX=	.tbz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pretty Quick Image Viewer

OPTIONS=	SORTING		"Enable sorting of loaded files" on \
		COMPOSITE	"Enable support for transparent windows" on \
		FADING		"Enable support for fading images" on \
		COMMANDS	"Enable support for external command execution" on \
		CONFIG		"Enable support for a configuration file" on

USE_BZIP2=	yes
USE_GNOME=	gtk20
CFLAGS+=	-DNO_INOTIFY -DBINARY_NAME=\"${PORTNAME}\"

MAN1=		pqiv.1
PORTDOCS=	README
PLIST_FILES=	bin/pqiv

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SORTING)
CFLAGS+=	-DNO_SORTING
SORTFILE=	# Empty
.else
SORTFILE=	lib/strnatcmp.c
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

post-patch:
	@(cd ${WRKSRC} && ${SED} 's|$$PACKAGE_VERSION|${PORTVERSION}|' \
		< pqiv.1.template > pqiv.1)

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} `${pkgconfig_DETECT} --libs --cflags gtk+-2.0 gthread-2.0` \
		${SORTFILE} pqiv.c -o pqiv)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pqiv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pqiv.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
