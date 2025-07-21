PORTNAME=	lv2
PORTVERSION=	1.18.10
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	https://lv2plug.in/spec/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open standard for audio plugins (successor to LADSPA)
WWW=		https://lv2plug.in/

LICENSE=	ISCL MIT
LICENSE_COMB=	multi
# Only lv2specgen.py is under MIT
LICENSE_FILE_ISCL=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdflib>0:textproc/py-rdflib@${PY_FLAVOR}

USES=		meson pkgconfig python:build shebangfix tar:xz

MESON_ARGS=	-Dtests=disabled
SHEBANG_FILES=	lv2specgen/lv2specgen.py
BINARY_ALIAS=	python3=${PYTHON_CMD}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS DOXYGEN EXAMPLES
OPTIONS_SUB=	yes

DOCS_BUILD_DEPENDS=	asciidoc:textproc/asciidoc

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			${PYTHON_PKGNAMEPREFIX}lxml5>0:devel/py-lxml5@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}rdflib>0:textproc/py-rdflib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR}
DOXYGEN_MESON_ENABLED=	docs

EXAMPLES_LIB_DEPENDS=	libsamplerate.so:audio/libsamplerate \
			libsndfile.so:audio/libsndfile
EXAMPLES_USES=		gnome
EXAMPLES_USE=		GNOME=cairo,glib20,gtk20
EXAMPLES_MESON_ENABLED=	plugins

.include <bsd.port.mk>
