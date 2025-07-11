PORTNAME=	orc
DISTVERSION=	0.4.41
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://gstreamer.freedesktop.org/data/src/orc/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and toolset to operate arrays of data
WWW=		https://gstreamer.freedesktop.org/projects/orc.html

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson pkgconfig tar:xz

MESON_ARGS=	--default-library=both \
		-Dbenchmarks=auto \
		-Dexamples=auto \
		-Dorc-target=all \
		-Dorc-test=auto \
		-Dtests=auto \
		-Dtools=auto
USE_LDCONFIG=	yes

PLIST_SUB=	LIBMINORVER=${PORTVERSION:E}

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc
DOCS_MESON_ENABLED=	gtk_doc

.include <bsd.port.mk>
