# New ports collection makefile for:	gtg
# Date created:				16 March 2009
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	gtg
PORTVERSION=	0.2.4
PORTREVISION=	5
CATEGORIES=	deskutils gnome python
MASTER_SITES=	http://launchpad.net/gtg/0.2/${PORTVERSION}/+download/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GTD organizer for the GNOME desktop environment

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/configobj.py:${PORTSDIR}/devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.82.4:${PORTSDIR}/devel/py-dbus \
		${PYTHON_SITELIBDIR}/xdg/__init__.py:${PORTSDIR}/devel/py-xdg \
		xset:${PORTSDIR}/x11/xset

FETCH_ARGS=	-pRr
USE_GNOME=	desktopfileutils pygobject pygtk2
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_PYTHON=	2.6-2.7
USE_PYDISTUTILS=	yes

MAN1=		gtg.1 gtg_new_task.1

OPTIONS=	CHEETAH "Needed for export plugin to work" off

.include <bsd.port.pre.mk>

.if defined(WITH_CHEETAH)
RUN_DEPENDS+=	${LOCALBASE}/bin/cheetah:${PORTSDIR}/devel/py-cheetah
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		${WRKSRC}/gtg.desktop ${WRKSRC}/GTG/__init__.py
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/gtg.desktop ${WRKSRC}/org.GTG.service

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
