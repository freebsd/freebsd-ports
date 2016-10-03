# $FreeBSD$

PORTNAME=	boiled-mozc
PORTVERSION=	0.7
#PORTREVISION=	0
CATEGORIES=	japanese editors elisp

MAINTAINER=	ume@FreeBSD.org
COMMENT=	Wrapper to mozc.el that offers modeless ("boil"ed) input style

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/mozc/mozc.el.gz:japanese/mozc-el

GH_ACCOUNT=	tadanagao
GH_TAGNAME=	v${PORTVERSION}

USE_GITHUB=	yes
USE_EMACS=	yes

PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}.el \
		${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}.elc

do-build:
	@cd ${WRKSRC} && ${EMACS_CMD} -batch -q -no-site-file -no-init-file \
		-f batch-byte-compile ${PORTNAME}.el

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.el \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.elc \
		${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.mk>
