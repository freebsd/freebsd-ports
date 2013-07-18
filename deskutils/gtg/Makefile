# $FreeBSD$

PORTNAME=	gtg
PORTVERSION=	0.3
CATEGORIES=	deskutils gnome python
MASTER_SITES=	https://launchpadlibrarian.net/122201197/

MAINTAINER=	rm@FreeBSD.org
COMMENT=	GTD organizer for the GNOME desktop environment

LICENSE=	GPLv3

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=0:${PORTSDIR}/devel/py-configobj \
		${PYTHON_PKGNAMEPREFIX}dbus>=0.82.4:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}xdg>=0:${PORTSDIR}/devel/py-xdg \
		${PYTHON_PKGNAMEPREFIX}liblarch>=2.1:${PORTSDIR}/devel/py-liblarch \
		xset:${PORTSDIR}/x11/xset

FETCH_ARGS=	-pRr
USE_GNOME=	pygobject pygtk2
USES=		gettext desktop-file-utils
INSTALLS_ICONS=	yes
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	yes

MAN1=		gtcli.1 gtg.1 gtg_new_task.1

OPTIONS_DEFINE=	CHEETAH
CHEETAH_DESC=	Needed for export plugin to work
OPTIONS_EXCLUDE=NLS DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCHEETAH}
RUN_DEPENDS+=	${LOCALBASE}/bin/cheetah:${PORTSDIR}/devel/py-cheetah
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|' \
		${WRKSRC}/org.gnome.GTG.service

.include <bsd.port.mk>
