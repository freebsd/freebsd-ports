PORTNAME=	nsgenbind
PORTVERSION=	0.8
CATEGORIES=	devel
MASTER_SITES=	http://download.netsurf-browser.org/libs/releases/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	nc@FreeBSD.org
COMMENT=	NetSurf Generator for JavaScript bindings

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	netsurf-buildsystem>=1.5:devel/netsurf-buildsystem \
		${LOCALBASE}/bin/flex:textproc/flex

USES=		bison gmake
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
MAKE_ENV+=	BUILD_CC="${CC}" \
		COMPONENT_TYPE="lib-shared" \
		FLEX="${LOCALBASE}/bin/flex"
PLIST_FILES=	bin/nsgenbind

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

.include <bsd.port.mk>
