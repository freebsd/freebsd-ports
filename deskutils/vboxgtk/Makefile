# Created by: Alexander Logvinov <avl@FreeBSD.org>
# $FreeBSD$

PORTNAME=	vboxgtk
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	deskutils emulators gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK frontend for VirtualBox

BROKEN=		Unfetchable (google code has gone away)

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/xpcom/vboxxpcom.py:emulators/virtualbox-ose

USES=		python
USE_PYTHON=	distutils autoplist
USE_GNOME=	gtk30 intltool
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/self.add_mo_files/d' \
		-e '/os.system("intltool/d' ${WRKSRC}/setup.py
.endif
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' ${WRKSRC}/bin/${PORTNAME}

.include <bsd.port.mk>
