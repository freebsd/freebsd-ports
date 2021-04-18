PORTNAME=	chibi-scheme
DISTVERSION=	0.9.1
CATEGORIES=	lang

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Minimal Scheme implementation for use as a C extension language

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	ashinn
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

MAKE_ARGS=	IMAGE_FILES="" \
		LDCONFIG=${TRUE}
ALL_TARGET=	all doc libchibi-scheme.a
TEST_TARGET=	test

PORTSCOUT=	skipv:stable
PLIST_SUB=	SOVERSION=${DISTVERSION}

PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} \
	    -e '/$$(SO)/s|$$(INSTALL_EXE) -m0755|$$(BSD_INSTALL_LIB)|' \
	    -e '/tools/s|$$(INSTALL) -m0755|$$(BSD_INSTALL_SCRIPT)|' \
	    -e 's|$$(INSTALL_EXE) -m0755|$$(BSD_INSTALL_PROGRAM)|' \
	    -e '/$$(MANDIR)/s|$$(INSTALL) -m0644|$$(BSD_INSTALL_MAN)|' \
	    -e 's|$$(INSTALL) -m0644|$$(BSD_INSTALL_DATA)|' \
	    ${WRKSRC}/Makefile
	@${REINPLACE_CMD} 's|-g -g3 -O3 ||' ${WRKSRC}/Makefile.detect

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/lib
	${INSTALL_DATA} ${WRKSRC}/doc/chibi.html ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/doc/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}/lib

.include <bsd.port.mk>
