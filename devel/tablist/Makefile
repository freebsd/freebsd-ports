PORTNAME=	tablist
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Emacs package for extended tabulated-list-mode

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	politza

NO_ARCH=	yes
PLIST_FILES=	${EMACS_SITE_LISPDIR}/tablist.el \
		${EMACS_SITE_LISPDIR}/tablist.elc \
		${EMACS_SITE_LISPDIR}/tablist-filter.el \
		${EMACS_SITE_LISPDIR}/tablist-filter.elc

do-build:
	${EMACS_CMD} -Q --batch -L ${WRKSRC} -f batch-byte-compile ${WRKSRC}/*.el

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.el ${WRKSRC}/*.elc \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
