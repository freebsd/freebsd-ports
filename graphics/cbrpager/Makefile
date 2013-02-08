# Created by: ijliao
# $FreeBSD$

PORTNAME=	cbrpager
PORTVERSION=	0.9.22
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION} \
		http://jcoppens.com/soft/cbrpager/img/:icons
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		snap.jpeg:icons
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Viewer for cbr (comic book archive) files

LICENSE=	GPLv3

BUILD_DEPENDS=	jpegtopnm:${PORTSDIR}/graphics/netpbm

GNU_CONFIGURE=	yes
USE_PKGCONFIG=	build
USE_GNOME=	libgnomeui
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

DESKTOP_ENTRIES="cbrPager" "Comic book viewer" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" \
		"${PORTNAME}" "Graphics;Viewer;GNOME;" true

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
PLIST_FILES+=	share/locale/es/LC_MESSAGES/${PORTNAME}.mo \
		share/locale/fr/LC_MESSAGES/${PORTNAME}.mo
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-configure:
.if !${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} 's|src po|src|' ${WRKSRC}/Makefile
.endif

post-build:
	@(cd ${WRKSRC} && \
		${LOCALBASE}/bin/jpegtopnm ${DISTDIR}/${DIST_SUBDIR}/snap.jpeg | \
		${LOCALBASE}/bin/pamscale .118 | ${LOCALBASE}/bin/pnmtopng > ${PORTNAME}.png)

post-install:
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.png ${PREFIX}/share/pixmaps

.include <bsd.port.mk>
