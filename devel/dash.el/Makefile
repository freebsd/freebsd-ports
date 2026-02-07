PORTNAME=	dash.el
DISTVERSION=	2.20.0
PORTREVISION=	1
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern list library for Emacs
WWW=		https://github.com/magnars/dash.el

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	magnars

NO_ARCH=	yes
PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/dash.el \
		${EMACS_VERSION_SITE_LISPDIR}/dash.elc

do-build:
	(cd ${WRKSRC} \
	&& ${EMACS_CMD} -Q -batch -L . -f batch-byte-compile dash.el)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} dash.el* \
	    ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR})

.include <bsd.port.mk>
