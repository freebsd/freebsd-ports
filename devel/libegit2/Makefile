PORTNAME=	libegit2
DISTVERSION=	g20200515
PORTREVISION=	3
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	Emacs bindings for libgit2

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cmake:noninja emacs pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	magit
GH_TAGNAME=	0ef8b13
USE_LDCONFIG=	yes

CMAKE_ON=	USE_SYSTEM_LIBGIT2

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} \
		's,%%LIBEGIT2_INSTALL_DIR%%,${PREFIX}/${EMACS_VERSION_SITE_LISPDIR},' \
		${WRKSRC}/libgit.el

post-build:
	(cd ${WRKSRC} \
	&& ${EMACS_CMD} -Q -batch -L . -f batch-byte-compile libgit.el)

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/../.build/libegit2.so \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/libgit.el ${WRKSRC}/libgit.elc \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
