PORTNAME=	photocollage
DISTVERSION=	1.4.5
PORTREVISION=	2
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Graphical tool to make photo collage posters
WWW=		https://github.com/adrienverge/PhotoCollage

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>0:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>:devel/py-six@${PY_FLAVOR} \
		${PY_PILLOW}

USES=		gettext-tools python
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|${PORTNAME}|${PORTNAME}-${PYTHON_VER}| ; \
		s|^Name.*|& (python${PYTHON_VER})|' \
		${WRKSRC}/data/${PORTNAME}.desktop
	@${REINPLACE_CMD} -E 's/photocollage\.(png|svg|desktop|appdata\.xml)/photocollage-${PYTHON_VER}.\1/' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -E 's/APP_NAME = "photocollage"/APP_NAME = "photocollage-${PYTHON_VER}"/' ${WRKSRC}/photocollage/__init__.py
	@cd ${WRKSRC} && for f in $$(${FIND} -E . -regex '.*\.(png|svg|desktop|appdata\.xml)'); do \
		${MV} $$f $$(${ECHO} $$f | ${SED} -E 's|photocollage\.([[:alpha:].]*)|photocollage-${PYTHON_VER}.\1|'); \
	done

.include <bsd.port.mk>
