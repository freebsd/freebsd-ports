# $FreeBSD$

PORTNAME=	boiled-mozc
PORTVERSION=	0.7
DISTVERSIONPREFIX=v
PORTREVISION=	6
CATEGORIES=	japanese editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Wrapper to mozc.el that offers modeless ("boil"ed) input style

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	ja-mozc-el${EMACS_PKGNAMESUFFIX}>0:japanese/mozc-el@${EMACS_FLAVOR}
RUN_DEPENDS=	ja-mozc-el${EMACS_PKGNAMESUFFIX}>0:japanese/mozc-el@${EMACS_FLAVOR}

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	tadanagao

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}.el \
		${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}.elc

do-build:
	@(cd ${WRKSRC} && ${EMACS_CMD} -batch -q -no-site-file -no-init-file \
		-f batch-byte-compile ${PORTNAME}.el)

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.el \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.elc \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.mk>
