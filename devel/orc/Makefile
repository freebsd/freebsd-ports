PORTNAME=	orc
DISTVERSION=	0.4.41
CATEGORIES=	devel
MASTER_SITES=	http://gstreamer.freedesktop.org/data/src/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library and toolset to operate arrays of data
WWW=		https://gstreamer.freedesktop.org/projects/orc.html

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson pkgconfig tar:xz
USE_LDCONFIG=	yes

PLIST_SUB+=	LIBMINORVER=${DISTVERSION:E}

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_ENABLED=	gtk_doc

.include <bsd.port.mk>
