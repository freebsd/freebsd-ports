# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	zim
PORTVERSION=	0.60
CATEGORIES=	editors python
MASTER_SITES=	http://www.zim-wiki.org/downloads/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Desktop wiki editor

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>=0:${PORTSDIR}/devel/py-xdg \
		${LOCALBASE}/bin/xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3

INSTALLS_ICONS=	yes
USES=		gettext desktop-file-utils
USE_GNOME=	gtk20 pygtk2 pygobject
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

MAN1=		zim.1

OPTIONS_DEFINE=	GNUR LATEX GRAPHVIZ SCROT GNUPLOT BZR GIT MERCURIAL DITAA
OPTIONS_EXCLUDE=DOCS NLS
GNUR_DESC=	Support of plot editor based on GNU R
SCROT_DESC=	Screenshot taking and inserting support
BZR_DESC=	Version control for notebooks using bzr
GIT_DESC=	Version control for notebooks using git
MERCURIAL_DESC=	Version control for notebooks using hg
DITAA_DESC=		Diagram editor support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNUR}
RUN_DEPENDS+=	R:${PORTSDIR}/math/R
.endif
.if ${PORT_OPTIONS:MLATEX}
USE_TEX=	latex
.endif
.if ${PORT_OPTIONS:MGRAPHVIZ}
RUN_DEPENDS+=	fdp:${PORTSDIR}/graphics/graphviz
.endif
.if ${PORT_OPTIONS:MSCROT}
RUN_DEPENDS+=	scrot:${PORTSDIR}/graphics/scrot
.endif
.if ${PORT_OPTIONS:MGNUPLOT}
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
.endif
.if ${PORT_OPTIONS:MBZR}
RUN_DEPENDS+=	bzr:${PORTSDIR}/devel/bzr
.endif
.if ${PORT_OPTIONS:MGIT}
RUN_DEPENDS+=	git:${PORTSDIR}/devel/git
.endif
.if ${PORT_OPTIONS:MMERCURIAL}
RUN_DEPENDS+=	hg:${PORTSDIR}/devel/mercurial
.endif
.if ${PORT_OPTIONS:MDITAA}
RUN_DEPENDS+=	ditaa:${PORTSDIR}/graphics/ditaa
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "s|decode('utf-8')|decode('utf-8','replace')|g" ${WRKSRC}/zim/utils.py

post-install:
	-@update-desktop-database

.include <bsd.port.mk>
