# New ports collection makefile for:	hgview
# Date created:		20 Nov 2008
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hgview
PORTVERSION=	0.11.2
CATEGORIES=	devel
MASTER_SITES=	http://ftp.logilab.org/pub/hgview/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Gtk or Qt4 based mercurial repository browser

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

MAN1=		hgview.1

OPTIONS=	GTK "GTK dependency" on \
		QT  "QT4 dependency" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GTK)
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gtk>=2.12.1:${PORTSDIR}/x11-toolkits/py-gtk2
.endif

.if defined(WITH_QT)
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/PyQt4/QtGui.so:${PORTSDIR}/x11-toolkits/py-qt4-gui
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/__pkginfo__.py

.include <bsd.port.post.mk>
