# Created by: Michael Beer <beerml@sigma6audio.de>
# $FreeBSD$

PORTNAME=	lv2
PORTVERSION=	1.14.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://lv2plug.in/spec/

MAINTAINER=	beerml@sigma6audio.de
COMMENT=	Open standard for audio plugins (successor to LADSPA)

LICENSE=	ISCL MIT
LICENSE_COMB=	multi
# Only lv2specgen.py is under MIT
LICENSE_FILE_ISCL=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lxml>0:devel/py-lxml \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}rdflib>0:textproc/py-rdflib

CONFLICTS_INSTALL=	lv2core

USES=		python shebangfix tar:bzip2 waf
SHEBANG_FILES=	lv2specgen/lv2specgen.py

OPTIONS_DEFINE=	DOXYGEN EXAMPLES
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen \
			${PYTHON_PKGNAMEPREFIX}rdflib>0:textproc/py-rdflib
DOXYGEN_CONFIGURE_ON=	--docs
DOXYGEN_PORTDOCS=	*

EXAMPLES_CONFIGURE_OFF=	--no-plugins
EXAMPLES_LIB_DEPENDS=	libsndfile.so:audio/libsndfile
EXAMPLES_USES=		pkgconfig
EXAMPLES_USE=		GNOME=cairo,gtk20
EXAMPLES_CONFIGURE_ENV=	CC='${CC} -Wl,--as-needed' # Gtk deps

post-install:
# Waf doesn't support changing pkg-config data install path
	@${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/*.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/
	@${RMDIR} ${STAGEDIR}${PREFIX}/lib/pkgconfig/
# Waf doesn't have built-in strip support
	@${FIND} ${STAGEDIR}${PREFIX}/lib/${PORTNAME} \
		-name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
