PORTNAME=	web-mode
PORTVERSION=	15.1
DISTVERSIONPREFIX=	v
PORTREVISION=	23
CATEGORIES=	editors elisp

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Autonomous Emacs major-mode for editing web templates
WWW=		https://web-mode.org

LICENSE=	GPLv2

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	fxbois

SUB_FILES=	web-mode-autoloads.el
SUB_LIST=	LISPDIR="${WEBMODE_LISPDIR}"
WEBMODE_LISPDIR=	${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
PLIST_FILES=	${EMACS_SITE_LISPDIR}/${PORTNAME}/web-mode.el.gz \
		${EMACS_SITE_LISPDIR}/web-mode-autoloads.el

CONFLICTS_INSTALL=	web-mode-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}/
	${INSTALL_DATA} ${WRKDIR}/web-mode-autoloads.el \
		${STAGEDIR}/${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/web-mode.el \
	${STAGEDIR}/${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

post-install:
	${GZIP_CMD} ${STAGEDIR}/${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}/*.el

.include <bsd.port.mk>
