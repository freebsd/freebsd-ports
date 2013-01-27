# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vboxgtk
PORTVERSION=	0.8.2
CATEGORIES=	deskutils emulators gnome
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	avl@FreeBSD.org
COMMENT=	GTK frontend for VirtualBox

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xpcom/vboxxpcom.py:${PORTSDIR}/emulators/virtualbox-ose

USE_PYTHON=	yes
USE_GNOME=	gtk30 pygtk2
USE_PYDISTUTILS=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/self.add_mo_files/d' \
		-e '/os.system("intltool/d' ${WRKSRC}/setup.py
.endif
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' ${WRKSRC}/bin/${PORTNAME}

.include <bsd.port.mk>
