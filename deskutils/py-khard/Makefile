PORTNAME=	khard
DISTVERSION=	0.20.0
CATEGORIES=	deskutils python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	herbert@gojira.at
COMMENT=	Console carddav client
WWW=		https://github.com/lucc/khard/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}setuptools-scm>=6.2:devel/py-setuptools-scm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx>=0,1:textproc/py-sphinx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-argparse>0:textproc/py-sphinx-argparse@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-autoapi>0:textproc/py-sphinx-autoapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sphinx-autodoc-typehints>0:textproc/py-sphinx-autodoc-typehints@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=5.0.6:devel/py-configobj@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.15:devel/py-ruamel.yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vdirsyncer>=0:deskutils/py-vdirsyncer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}vobject>=0.9.5:deskutils/py-vobject@${PY_FLAVOR}

USES=		gmake python:-3.11
USE_PYTHON=	autoplist pep517

NO_ARCH=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	share/zsh/site-functions/_khard \
		share/zsh/site-functions/_email-khard \
		${EXAMPLESDIR}/khard.conf.example \
		${EXAMPLESDIR}/template.yaml \
		share/man/man1/khard.1.gz \
		share/man/man5/khard.conf.5.gz

post-patch:
	@${REINPLACE_CMD} \
		-e 's|sphinx-build|${LOCALBASE}/bin/sphinx-build-${PYTHON_VER}|g' \
		-e 's|sphinx-apidoc|${LOCALBASE}/bin/sphinx-apidoc-${PYTHON_VER}|g' \
		${WRKSRC}/doc/Makefile

pre-build:
	(cd ${WRKSRC}/doc && ${MAKE_CMD} man)

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions \
		 ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/misc/zsh/_khard \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/misc/zsh/_email-khard \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions
	(cd ${WRKSRC}/doc/source/examples/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	${INSTALL_MAN} ${WRKSRC}/doc/build/man/khard.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/build/man/khard.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5

.include <bsd.port.mk>
