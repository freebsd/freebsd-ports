PORTNAME=	showdown
DISTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Simple markdown viewer, written in Vala and GTK 3

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libmarkdown.a:textproc/discount \
		valac:lang/vala
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk3

USES=		compiler:c++11-lang desktop-file-utils gmake gnome \
		pkgconfig xorg
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 pango
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	craigbarnes

MAKEFILE=	GNUmakefile
MAKE_ARGS=	V=1 prefix=${PREFIX}
INSTALLS_ICONS=	yes

PORTDOCS=	README.md

PLIST_FILES=	bin/showdown \
		share/applications/io.gitlab.craigbarnes.Showdown.desktop \
		share/icons/hicolor/scalable/apps/showdown.svg

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
EXTRA_PATCHES=	${FILESDIR}/extra-patch-GNUmakefile
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/showdown

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
