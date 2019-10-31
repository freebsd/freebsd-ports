# Created by: Janni
# $FreeBSD$

PORTNAME=	gxemul
PORTVERSION=	0.6.2
CATEGORIES=	emulators
MASTER_SITES=	http://gavare.se/gxemul/src/

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Instruction-level machine emulator

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-valgrind \
		--without-unittests
CONFIGURE_ENV=	CXX=${CXX} \
		LOCALBASE=${LOCALBASE} \
		PREFIX=${PREFIX}

# Avoid auto-detecting Doxygen.  We do not need source code documentation.
# The handbook is quite comprehensive already.
BINARY_ALIAS=	doxygen=${FALSE}

PLIST_FILES=	bin/gxemul \
		man/man1/gxemul.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=		DOCS X11
OPTIONS_DEFAULT=	X11

X11_RUN_DEPENDS=	xterm:x11/xterm
X11_USES=		xorg
X11_USE=		XORG=x11
X11_CONFIGURE_OFF=	--disable-x

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gxemul ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/gxemul.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
