PORTNAME=	sly
DISTVERSION=	1.0.43-20240809
PORTREVISION=	2
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	olce.freebsd.ports@certner.fr
COMMENT=	Sylvester the Cat's Common Lisp IDE for Emacs
WWW=		https://github.com/joaotavora/sly

LICENSE=	PD

USES=		emacs gmake
USE_GITHUB=	yes
GH_ACCOUNT=	joaotavora
GH_TAGNAME=	742355f7554ab6c46e5c1c9bdb89068f55359eaa

NO_ARCH=	yes

INFO=		sly

ALL_TARGET=	all doc-sly.info

PLIST_THIS_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/sly
THIS_LISPDIR=		${PREFIX}/${PLIST_THIS_LISPDIR}
PLIST_SUB+=		THIS_LISPDIR=${PLIST_THIS_LISPDIR}

PORTSCOUT=	limit:^[0-9]

OPTIONS_DEFINE=	DOCS DOCS_PDF
OPTIONS_DEFAULT=DOCS DOCS_PDF

DOCS_PDF_DESC=	Build PDF documentation (requires DOCS)

ROOT_DOCS_FILES=	CONTRIBUTING.md NEWS.md PROBLEMS.md README.md
GENERATED_DOCS_FILES=	sly.html
DOCS_BUILD_DEPENDS=	texinfo>=5.2:print/texinfo

DOCS_PDF_IMPLIES=	DOCS
DOCS_PDF_USES=	tex
DOCS_PDF_USE=	TEX=latex:build,pdftex:build,dvipsk:build

.include <bsd.port.options.mk>

.if !empty(PORT_OPTIONS:MDOCS_PDF)
GENERATED_DOCS_FILES+=	sly.pdf sly-refcard.pdf
.endif

ALL_TARGET+=	${GENERATED_DOCS_FILES:%=doc-%}

PORTDOCS:=	CONTRIBUTING.md NEWS.md PROBLEMS.md README.md \
		${GENERATED_DOCS_FILES}

do-install:
	@${MKDIR} ${STAGEDIR}${THIS_LISPDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${THIS_LISPDIR} \
		"! ( -depth 1 ( -name Makefile -o -name *\.md -o \
				-name \.[^.]* ) -o \
			-path \./doc* )")
	${INSTALL_DATA} ${WRKSRC}/doc/${INFO}.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}

# DOCS_PDF depends on DOCS
post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${ROOT_DOCS_FILES:%=${WRKSRC}/%} \
		${GENERATED_DOCS_FILES:%=${WRKSRC}/doc/%} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
