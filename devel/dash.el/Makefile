PORTNAME=	dash.el
PORTVERSION=	2.18.1
PORTREVISION=	1
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	Modern list library for Emacs

LICENSE=	GPLv3

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	magnars

NO_ARCH=	yes
PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/dash.el \
		${EMACS_VERSION_SITE_LISPDIR}/dash.elc \
		${EMACS_VERSION_SITE_LISPDIR}/dash-functional.el \
		${EMACS_VERSION_SITE_LISPDIR}/dash-functional.elc

do-build:
	(cd ${WRKSRC} \
	&& ${EMACS_CMD} -Q -batch -L . -f batch-byte-compile *.el)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} *.el* \
	    ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR})

.include <bsd.port.mk>
