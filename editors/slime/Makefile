PORTNAME=	slime
DISTVERSIONPREFIX=	v
DISTVERSION=	2.26.1-9
PORTREVISION=	14
DISTVERSIONSUFFIX=	-gf368e22a
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Superior Lisp Interaction Mode for Emacs
WWW=		https://common-lisp.net/project/slime/

LICENSE=	PD

BUILD_DEPENDS=	texinfo>=5.2:print/texinfo

USES=		emacs gmake
USE_GITHUB=	yes

ALL_TARGET=	all contrib-compile doc-slime.info
INFO=		slime
NO_ARCH=	yes
PORTDOCS=	CONTRIBUTING.md NEWS PROBLEMS README.md
SUB_FILES=	pkg-message
SUB_LIST=	SLIME_LISPDIR="${SLIME_LISPDIR}"

OPTIONS_DEFINE=	DOCS

SLIME_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/slime

do-install:
	@${MKDIR} ${STAGEDIR}${SLIME_LISPDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${SLIME_LISPDIR} \
		"! ( -name CONTRIBUTING.md -o -name NEWS -o -name PROBLEMS \
		-o -name README.md -o -name Makefile -o -name doc \
		-o -path \./doc/* )")

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/contrib/README.md \
		${STAGEDIR}${DOCSDIR}/README-contrib.md
	(cd ${INSTALL_WRKSRC}/doc && ${INSTALL_DATA} slime-refcard.pdf \
		slime-small.pdf ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
