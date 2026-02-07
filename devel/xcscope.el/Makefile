PORTNAME=	xcscope.el
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5
PORTREVISION=	10
CATEGORIES=	devel

MAINTAINER=	jhb@FreeBSD.org
COMMENT=	Emacs minor mode for using cscope
WWW=		https://github.com/dkogan/xcscope.el

LICENSE=	GPLv2+

RUN_DEPENDS=	cscope:devel/cscope

USES=		emacs
EMACS_NO_DEPENDS=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	dkogan

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/xcscope.el

do-install:
	${INSTALL_DATA} ${WRKSRC}/xcscope.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
