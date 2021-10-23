PORTNAME=	dash.el
DISTVERSION=	2.19.1
PORTREVISION=	2
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Modern list library for Emacs

LICENSE=	GPLv3

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	magnars

NO_ARCH=	yes
PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/dash-functional.el \
		${EMACS_VERSION_SITE_LISPDIR}/dash-functional.elc \
		${EMACS_VERSION_SITE_LISPDIR}/dash.el \
		${EMACS_VERSION_SITE_LISPDIR}/dash.elc

do-build:
	(cd ${WRKSRC} \
	&& ${EMACS_CMD} -Q -batch -L . -f batch-byte-compile *.el)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.el* \
	    ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR})

.include <bsd.port.mk>
