PORTNAME=	lv2
PORTVERSION=	1.18.2
CATEGORIES=	audio
MASTER_SITES=	https://lv2plug.in/spec/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open standard for audio plugins (successor to LADSPA)

LICENSE=	ISCL MIT
LICENSE_COMB=	multi
# Only lv2specgen.py is under MIT
LICENSE_FILE_ISCL=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rdflib>0:textproc/py-rdflib@${PY_FLAVOR}

USES=		python shebangfix tar:bzip2 waf

SHEBANG_FILES=	lv2specgen/lv2specgen.py

OPTIONS_DEFINE=	DOCS DOXYGEN EXAMPLES
OPTIONS_SUB=	yes

DOXYGEN_IMPLIES=	DOCS
DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}rdflib>0:textproc/py-rdflib@${PY_FLAVOR} \
			${PYTHON_PKGNAMEPREFIX}markdown>0:textproc/py-markdown@${PY_FLAVOR}
DOXYGEN_CONFIGURE_ON=	--docs
DOXYGEN_PORTDOCS=	*

EXAMPLES_LIB_DEPENDS=	libsndfile.so:audio/libsndfile \
			libfontconfig.so:x11-fonts/fontconfig \
			libfreetype.so:print/freetype2
EXAMPLES_USES=		pkgconfig gnome
EXAMPLES_USE=		GNOME=atk,cairo,gdkpixbuf2,glib20,gtk20,pango
EXAMPLES_CONFIGURE_OFF=	--no-plugins

post-install:
# Waf doesn't have built-in strip support
	@${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME} \
		-name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
