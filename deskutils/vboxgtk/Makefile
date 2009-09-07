# New ports collection makefile for:	vboxgtk
# Date created:				13 June 2009
# Whom:					Alexander Logvinov <avl@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vboxgtk
PORTVERSION=	0.5.0
CATEGORIES=	deskutils emulators gnome
MASTER_SITES=	SF

MAINTAINER=	avl@FreeBSD.org
COMMENT=	GTK frontend for VirtualBox

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gobject/_gobject.so:${PORTSDIR}/devel/py-gobject \
		${PYTHON_SITELIBDIR}/virtualbox/xpcom/vboxxpcom.py:${PORTSDIR}/emulators/virtualbox

USE_PYTHON=	yes
USE_GNOME=	pygtk2
USE_PYDISTUTILS=	yes
INSTALLS_ICONS=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e '/self.add_mo_files/d' \
		-e '/os.system("intltool/d' ${WRKSRC}/setup.py
.endif
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' ${WRKSRC}/bin/${PORTNAME}

.include <bsd.port.mk>
