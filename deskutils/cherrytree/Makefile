PORTNAME=	cherrytree
PORTVERSION=	1.5.0
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	https://www.giuspen.com/software/ \
		https://github.com/giuspen/cherrytree/releases/download/v${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Advanced hierarchical note-taking application
WWW=		https://www.giuspen.com/cherrytree/

LICENSE=	GPLv3+

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libenchant-2.so:textproc/enchant2 \
		libfmt.so:devel/libfmt \
		libfribidi.so:converters/fribidi \
		libgspell-1.so:textproc/gspell \
		libharfbuzz.so:print/harfbuzz \
		libspdlog.so:devel/spdlog \
		libuchardet.so:textproc/uchardet

USES=		cmake compiler:c++17-lang desktop-file-utils gnome \
		pkgconfig python:build sqlite tar:xz
USE_GNOME=	gtkmm30 gtksourceview4 libxml++26

CMAKE_ARGS=	-DPYTHON_EXEC:FILEPATH=${PYTHON_CMD} \
		-DBUILD_TESTING:BOOL=OFF

OPTIONS_DEFINE=	DOCS NLS VTE
OPTIONS_SUB=	yes

NLS_USES=	gettext-tools
NLS_CMAKE_OFF=	-DUSE_NLS:BOOL=OFF

VTE_DESC=	Virtual terminal support
VTE_USE=	GNOME=vte3
VTE_CMAKE_OFF=	-DUSE_VTE:BOOL=OFF

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/changelog.txt ${WRKSRC}/docs/* \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
