PORTNAME=	cp5022x
PORTVERSION=	0.0.20120324
PORTREVISION=	3
CATEGORIES=	japanese elisp
PKGNAMESUFFIX=	-el${EMACS_PKGNAMESUFFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	CP50220 and CP51932 coding system support for Emacsen

LICENSE=	GPLv3+

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	awasira
GH_PROJECT=	cp5022x.el
GH_TAGNAME=	ea7327d

PLIST_FILES=	${EMACS_SITE_LISPDIR}/cp5022x.el.gz \
		${EMACS_SITE_LISPDIR}/cp5022x.elc

do-build:
	cd ${BUILD_WRKSRC} && \
	    ${EMACS_CMD} -batch -q -no-site-file -no-init-file \
	    -f batch-byte-compile cp5022x.el && \
	    ${GZIP_CMD} cp5022x.el

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR} && \
	cd ${INSTALL_WRKSRC} && \
	    ${INSTALL_DATA} cp5022x.elc cp5022x.el.gz \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
