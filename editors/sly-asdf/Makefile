PORTNAME=	sly-asdf
DISTVERSION=	0.2.0-20221119
PORTREVISION=	7
PORTEPOCH=	1
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	olce.freebsd.ports@certner.fr
COMMENT=	SLY support for ASDF
WWW=		https://github.com/mmgeorge/sly-asdf

LICENSE=	GPLv3

MY_DEPENDS=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/sly/sly.el:editors/sly@${EMACS_FLAVOR}
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	mmgeorge
GH_TAGNAME=	6f9d751469bb82530db1673c22e7437ca6c95f45

NO_ARCH=	yes

EMACS_COMPILE=	${EMACS_CMD} --batch --no-site-file -L ${WRKSRC} \
		-f batch-byte-compile

PLIST_THIS_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
THIS_LISPDIR=		${PREFIX}/${PLIST_THIS_LISPDIR}
PLIST_SUB+=		THIS_LISPDIR=${PLIST_THIS_LISPDIR}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	README.md

post-patch:
	cd ${WRKSRC} && ${RM} *flymake*

do-build:
	cd ${WRKSRC} && ${EMACS_COMPILE} sly-*.el

do-install:
	@${MKDIR} ${STAGEDIR}${THIS_LISPDIR}
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${THIS_LISPDIR} \
		"! ( -depth 1 ( ${PORTDOCS:C/^(.*)$/-name \1 -o/} \
			-name LICENSE -o -name *\.md ) -o \
			-path \./test* -o -path \./.[^.]* -o \
			-name *\.orig )")

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:%=${WRKSRC}/%} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
