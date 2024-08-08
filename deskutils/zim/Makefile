PORTNAME=	zim
DISTVERSION=	0.75.2
PORTREVISION=	4
CATEGORIES=	deskutils python
MASTER_SITES=	https://www.zim-wiki.org/downloads/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Desktop wiki editor
WWW=		https://www.zim-wiki.org

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR} \
		${PY_SETUPTOOLS}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${PY_FLAVOR} \
		xdg-open:devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR}

USES=		cpe desktop-file-utils gettext gnome python shared-mime-info
CPE_VENDOR=	zim-wiki
USE_GNOME=	gtk30 pygobject3
USE_PYTHON=	autoplist pep517 noflavors

NO_ARCH=	yes

OPTIONS_DEFINE=		DITAA GIT GNUPLOT GNUR GRAPHVIZ LATEX \
			MERCURIAL SCROT

DITAA_DESC=		Diagram editor support
DITAA_RUN_DEPENDS=	ditaa:graphics/ditaa
GIT_DESC=		Version control for notebooks using git
GIT_RUN_DEPENDS=	git:devel/git
GNUPLOT_RUN_DEPENDS=	gnuplot:math/gnuplot
GNUR_DESC=		Support of plot editor based on GNU R
GNUR_RUN_DEPENDS=	R:math/R
GRAPHVIZ_RUN_DEPENDS=	fdp:graphics/graphviz
LATEX_USES=		tex
LATEX_USE=		TEX=latex:run
MERCURIAL_DESC=		Version control for notebooks using hg
MERCURIAL_RUN_DEPENDS=	${PY_MERCURIAL}
SCROT_DESC=		Screenshot taking and inserting support
SCROT_RUN_DEPENDS=	scrot:graphics/scrot

post-patch:
	@${REINPLACE_CMD} -e \
		'/.command.install /s|distutils|setuptools|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
