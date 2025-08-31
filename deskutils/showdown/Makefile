PORTNAME=	showdown
DISTVERSION=	0.6
PORTREVISION=	6
CATEGORIES=	deskutils

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple markdown viewer, written in Vala and GTK 3
WWW=		https://github.com/craigbarnes/showdown

LICENSE=	GPLv3

BUILD_DEPENDS=	${LOCALBASE}/lib/libmarkdown.a:textproc/discount
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libwebkit2gtk-4.0.so:www/webkit2-gtk@40

USES=		compiler:c++11-lang desktop-file-utils gmake gnome \
		pkgconfig vala:build xorg
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30 pango
USE_XORG=	x11
USE_GITHUB=	yes
GH_ACCOUNT=	craigbarnes

MAKEFILE=	GNUmakefile
MAKE_ARGS=	V=1 prefix=${PREFIX}

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
