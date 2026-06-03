PORTNAME=	pkg-info.el
PORTVERSION=	0.6
PORTREVISION=	20
CATEGORIES=	devel elisp

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Provide information about Emacs packages
WWW=		https://github.com/lunaryorn/pkg-info.el

LICENSE=	GPLv3

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	lunaryorn

CONFLICTS_INSTALL=	pkg-info.el-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${EMACS_SITE_LISPDIR}/pkg-info.el

do-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PLIST_FILES:M*.el:T} \
	    ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR})

.include <bsd.port.mk>
