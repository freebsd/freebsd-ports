# Created by: Thomas Gellekum <tg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	skencil
PORTVERSION=	1.0.a784
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
PROJECTHOST=	sk1
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.a/alpha_rev/}

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Interactive drawing program

LICENSE=	LGPL20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}reportlab2>=0:${PORTSDIR}/print/py-reportlab2 \
		${PYTHON_PKGNAMEPREFIX}tkinter>0:${PORTSDIR}/x11-toolkits/py-tkinter \
		${PYXML}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}alpha

USE_XORG=	x11 xext
USE_TCL_BUILD=	yes
USE_TCL=	yes
USE_TK_BUILD=	yes
USE_TK=		yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PYDISTUTILS_EGGINFO=	${PORTNAME}-${PORTVERSION:R}alpha-py${PYTHON_VER}.egg-info

CFLAGS+=	-I${TK_INCLUDEDIR} -I${LOCALBASE}/include \
		-L${LOCALBASE}/lib

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS NLS

NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
	 @${REINPLACE_CMD} -e \
		"s|/usr/include|${LOCALBASE}/include|g ; \
		 s|/usr/lib|${LOCALBASE}/lib|g ; \
		 /tcl_ver/s|8\.[0-9]|${TCL_VER:S/.//}|g ; \
		 /libtcl/s|8\.[0-9]|${TCL_VER:S/.//}|g ; \
		 /libraries/s|tcl_ver\])|tcl_ver, 'intl'])|g ; \
		 s|/usr/share|${PREFIX}/share|g" ${WRKSRC}/setup.py

.if ! ${PORT_OPTIONS:MNLS}
	 @${REINPLACE_CMD} -e 's| + messages_dirs||' \
		${WRKSRC}/setup.py
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
