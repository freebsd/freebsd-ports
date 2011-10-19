# New ports collection makefile for:	zim
# Date created:		2006-03-21
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	zim
PORTVERSION=	0.53
PORTREVISION=	1
CATEGORIES=	editors python
MASTER_SITES=	http://www.zim-wiki.org/downloads/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A Desktop Wiki Editor

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}xdg>=0:${PORTSDIR}/devel/py-xdg \
		${LOCALBASE}/bin/xdg-open:${PORTSDIR}/devel/xdg-utils \
		${PYTHON_PKGNAMEPREFIX}sqlite3>=0:${PORTSDIR}/databases/py-sqlite3

INSTALLS_ICONS=	yes
USE_GETTEXT=	yes
USE_GNOME=	desktopfileutils gtk20 pygtk2 pygobject
USE_PYTHON=	2.5-2.7
USE_PYDISTUTILS=	yes

MAN1=		zim.1

OPTIONS=	GNUR "Add support of plot editor based on GNU R" Off \
		LATEX "Add equation editor support" Off \
		GRAPHVIZ "Add diagram editor support" Off \
		SCROT "Add screenshot taking and inserting support" Off \
		GNUPLOT "Add plot editor support" Off \
		BZR "Add version control for notebooks support" Off

.include <bsd.port.pre.mk>

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
RUN_DEPENDS+=	bzr:${PORTSDIR}/devel/bazaar-ng
.endif

.if ${PYTHON_REL} < 260
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.0.9:${PORTSDIR}/devel/py-simplejson
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/setup.py

post-install:
	-@update-desktop-database

.include <bsd.port.post.mk>
