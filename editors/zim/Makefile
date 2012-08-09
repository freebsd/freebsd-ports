# New ports collection makefile for:	zim
# Date created:		2006-03-21
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	zim
PORTVERSION=	0.56
PORTREVISION=	3
CATEGORIES=	editors python
MASTER_SITES=	http://www.zim-wiki.org/downloads/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Desktop wiki editor

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>=0:${PORTSDIR}/devel/py-xdg \
		${LOCALBASE}/bin/xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3

INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_GNOME=	desktopfileutils gtk20 pygtk2 pygobject
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

MAN1=		zim.1

OPTIONS=	GNUR "Add support of plot editor based on GNU R" Off \
		LATEX "Add equation editor support" Off \
		GRAPHVIZ "Add diagram editor support" Off \
		SCROT "Add screenshot taking and inserting support" Off \
		GNUPLOT "Add plot editor support" Off \
		BZR "Use bzr for notebooks version control support" Off \
		GIT "Use git for notebooks version control support" Off \
		MERCURIAL "Use hg for notebooks version control support" Off \
		DITAA "Add diagram editor support" Off

.include <bsd.port.options.mk>

.if defined(WITH_GNUR)
RUN_DEPENDS+=	R:${PORTSDIR}/math/R
.endif
.if defined(WITH_LATEX)
RUN_DEPENDS+=	latex:${PORTSDIR}/print/teTeX-base
.endif
.if defined(WITH_GRAPHVIZ)
RUN_DEPENDS+=	fdp:${PORTSDIR}/graphics/graphviz
.endif
.if defined(WITH_SCROT)
RUN_DEPENDS+=	scrot:${PORTSDIR}/graphics/scrot
.endif
.if defined(WITH_GNUPLOT)
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
.endif
.if defined(WITH_BZR)
RUN_DEPENDS+=	bzr:${PORTSDIR}/devel/bzr
.endif
.if defined(WITH_GIT)
RUN_DEPENDS+=	git:${PORTSDIR}/devel/git
.endif
.if defined(WITH_MERCURIAL)
RUN_DEPENDS+=	hg:${PORTSDIR}/devel/mercurial
.endif
.if defined(WITH_DITAA)
RUN_DEPENDS+=	ditaa:${PORTSDIR}/graphics/ditaa
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e "s|decode('utf-8')|decode('utf-8','replace')|g" ${WRKSRC}/zim/utils.py

post-install:
	-@update-desktop-database

.include <bsd.port.mk>
