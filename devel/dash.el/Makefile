PORTNAME=	dash.el
DISTVERSION=	2.20.0
PORTREVISION=	2
CATEGORIES=	devel elisp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern list library for Emacs
WWW=		https://github.com/magnars/dash.el

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	magnars

CONFLICTS_INSTALL=	dash.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${EMACS_SITE_LISPDIR}/dash.el

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} dash.el \
	    ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR})

.include <bsd.port.mk>
