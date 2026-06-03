PORTNAME=	boiled-mozc
PORTVERSION=	0.7
DISTVERSIONPREFIX=v
PORTREVISION=	26
CATEGORIES=	japanese editors elisp

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Wrapper to mozc.el that offers modeless ("boil"ed) input style
WWW=		https://github.com/tadanagao/boiled-mozc

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	ja-mozc-el>0:japanese/mozc-el
RUN_DEPENDS=	ja-mozc-el>0:japanese/mozc-el

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	tadanagao

CONFLICTS_INSTALL=	ja-boiled-mozc-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	${EMACS_SITE_LISPDIR}/${PORTNAME}.el

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}

.include <bsd.port.mk>
