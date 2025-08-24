PORTNAME=	xschem
DISTVERSION=	3.4.7
CATEGORIES=	cad

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Schematic capture and edit program for VLSI/ASIC/Analog designs
WWW=		https://xschem.sourceforge.io/stefan/index.html

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	flex:textproc/flex

USES=		bison gnome jpeg localbase:ldflags tk:86 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	StefanSchippers
USE_GNOME=	cairo
USE_XORG=	x11 xcb xpm

CFLAGS+=	-I${TCL_INCLUDEDIR} -I${TK_INCLUDEDIR}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

pre-build:
	@cd ${WRKSRC} && ./configure --CFLAGS='${CFLAGS}' --LDFLAGS='${LDFLAGS}'

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE}

post-install:
	@cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} rawtovcd xschem

post-install-DOCS-off:
	@${RM} -r ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
