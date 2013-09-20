# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	skencil
PORTVERSION=	1.0.a784
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/alpha_rev/}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Interactive drawing program

LICENSE=	LGPL20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}reportlab>0:${PORTSDIR}/print/py-reportlab \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYXML}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}alpha

PROJECTHOST=	sk1
USE_XORG=	x11 xext
USE_TCL_BUILD=	yes
USE_TCL=	yes
USE_TK_BUILD=	yes
USE_TK=		yes
USES=		gettext
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PYDISTUTILS_EGGINFO=	${PORTNAME}-${PORTVERSION:R}alpha-py${PYTHON_VER}.egg-info

CFLAGS+=	-I${TK_INCLUDEDIR} -I${LOCALBASE}/include \
		-L${LOCALBASE}/lib

PORTDOCS=	README

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	 @${REINPLACE_CMD} -e \
		"s|/usr/include|${LOCALBASE}/include|g ; \
		 s|/usr/lib|${LOCALBASE}/lib|g ; \
		 /tcl_ver/s|8\.[0-9]|${TCL_VER:S/.//}|g ; \
		 /libtcl/s|8\.[0-9]|${TCL_VER:S/.//}|g ; \
		 /libraries/s|tcl_ver\])|tcl_ver, 'intl'])|g ; \
		 s|/usr/share|${PREFIX}/share|g" ${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
