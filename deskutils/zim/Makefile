# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	zim
PORTVERSION=	0.67
CATEGORIES=	deskutils python
MASTER_SITES=	http://www.zim-wiki.org/downloads/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Desktop wiki editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>0:devel/py-xdg@${FLAVOR} \
		xdg-open:devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${FLAVOR}

NO_ARCH=	yes
USES=		desktop-file-utils gettext python:-2.7 shared-mime-info
USE_GNOME=	pygtk2
USE_PYTHON=	autoplist distutils
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		BZR DITAA GIT GNUPLOT GNUR GRAPHVIZ LATEX \
			MERCURIAL SCROT

DITAA_DESC=		Diagram editor support
DITAA_RUN_DEPENDS=	ditaa:graphics/ditaa
BZR_DESC=		Version control for notebooks using bzr
BZR_RUN_DEPENDS=	bzr:devel/bzr
GIT_DESC=		Version control for notebooks using git
GIT_RUN_DEPENDS=	git:devel/git
GNUPLOT_RUN_DEPENDS=	gnuplot:math/gnuplot
GNUR_DESC=		Support of plot editor based on GNU R
GNUR_RUN_DEPENDS=	R:math/R
GRAPHVIZ_RUN_DEPENDS=	fdp:graphics/graphviz
LATEX_USE=		tex=latex:run
MERCURIAL_DESC=		Version control for notebooks using hg
MERCURIAL_RUN_DEPENDS=	hg:devel/mercurial
SCROT_DESC=		Screenshot taking and inserting support
SCROT_RUN_DEPENDS=	scrot:graphics/scrot

post-patch:
	@${REINPLACE_CMD} -e \
		'/.command.install /s|distutils|setuptools| ; \
		 s|share/man|man| ; \
		 /.skip_xdg_cmd = /s|0|1|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
