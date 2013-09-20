# Created by: Martin Tournoij <carpetsmoker@xs4all.nl>
# $FreeBSD$

PORTNAME=	pqiv
PORTVERSION=	0.12
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GHC
EXTRACT_SUFX=	.tbz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Pretty Quick Image Viewer

LICENSE=	GPLv2

OPTIONS_DEFINE=	SORTING COMPOSITE FADING COMMANDS CONFIG ANIMATIONS DOCS
OPTIONS_DEFAULT=SORTING COMPOSITE FADING COMMANDS CONFIG ANIMATIONS
SORTING_DESC=	Enable sorting of loaded files
COMPOSITE_DESC=	Enable support for transparent windows
FADING_DESC=	Enable support for fading images
COMMANDS_DESC=	Enable support for external command execution
CONFIG_DESC=	Enable support for a configuration file
ANIMATIONS_DESC=Enable support for animations

USE_GITHUB=	yes
GH_ACCOUNT=	phillipberndt

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		pkgconfig
USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_CSTD=	gnu89
CFLAGS+=	-DNO_INOTIFY -DBINARY_NAME=\"${PORTNAME}\"

MAN1=		pqiv.1
PORTDOCS=	README.markdown
PLIST_FILES=	bin/pqiv

CPPFLAGS+=	`pkg-config --cflags gtk+-2.0 gthread-2.0`
LDFLAGS+=	`pkg-config --libs gtk+-2.0 gthread-2.0`

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MSORTING)
CFLAGS+=	-DNO_SORTING
SORTFILE=	# Empty
.else
SORTFILE=	lib/strnatcmp.c
.endif
.if empty(PORT_OPTIONS:MCOMPOSITE)
CFLAGS+=	-DNO_COMPOSITING
.endif
.if empty(PORT_OPTIONS:MFADING)
CFLAGS+=	-DNO_FADING
.endif
.if empty(PORT_OPTIONS:MCOMMANDS)
CFLAGS+=	-DNO_COMMANDS
.endif
.if empty(PORT_OPTIONS:MCONFIG)
CFLAGS+=	-DNO_CONFIG_FILE
.endif
.if empty(PORT_OPTIONS:MANIMATIONS)
CFLAGS+=	-DNO_ANIMATIONS
.endif

post-patch:
	@(cd ${PATCH_WRKSRC} && ${SED} 's|$$PACKAGE_VERSION|${PORTVERSION}| ; \
		 s|$$BINARY_NAME|${PORTNAME}|' < pqiv.1.template > pqiv.1)

do-build:
	(cd ${BUILD_WRKSRC} && ${CC} ${CPPFLAGS} ${CFLAGS} ${SORTFILE} pqiv.c \
		-o pqiv ${LDFLAGS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pqiv ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pqiv.1 ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.markdown ${DOCSDIR}
.endif

.include <bsd.port.mk>
