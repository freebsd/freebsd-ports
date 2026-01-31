PORTNAME=	orc
PORTVERSION=	0.4.42
CATEGORIES=	devel
MASTER_SITES=	https://gstreamer.freedesktop.org/data/src/orc/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library and toolset to operate arrays of data
WWW=		https://gstreamer.freedesktop.org/projects/orc.html \
		https://gitlab.freedesktop.org/gstreamer/orc

LICENSE=	BSD2CLAUSE BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson pkgconfig tar:xz

MESON_ARGS=	--default-library=both \
		-Dbenchmarks=auto \
		-Dexamples=auto \
		-Dorc-target=all \
		-Dorc-test=auto \
		-Dtests=auto
MESON_DISABLED=	hotdoc
MESON_ENABLED=	tools
USE_LDCONFIG=	yes

PLIST_SUB=	LIBMINORVER=${PORTVERSION:E}

.include <bsd.port.mk>
