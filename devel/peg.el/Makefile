PORTNAME=	peg.el
DISTVERSION=	1.0.1
PORTREVISION=	3
CATEGORIES=	devel elisp
MASTER_SITES=	https://elpa.gnu.org/packages/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTNAME=	peg-${DISTVERSION}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Parsing expression grammars in Emacs lisp
WWW=		https://elpa.gnu.org/packages/peg.html

LICENSE=	GPLv3+

DEPRECATED=	Emacs 30 and later include peg.el as standard library
EXPIRATION_DATE=	2025-03-31

USES=		emacs tar

NO_ARCH=	yes
PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/peg.el \
		${EMACS_VERSION_SITE_LISPDIR}/peg.elc

do-build:
	(cd ${WRKSRC} \
	&& ${EMACS_CMD} -Q -batch -L . -f batch-byte-compile peg.el)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} peg.el* \
	    ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR})

.include <bsd.port.mk>
