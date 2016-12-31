# $FreeBSD$

PORTNAME=	cask
PORTVERSION=	0.8.1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel elisp

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Project management tool for Emacs

LICENSE=	GPLv3

USE_GITHUB=	yes
USE_EMACS=	yes
USES=		python
NO_BUILD=	yes

PLIST_FILES=	%%EMACS_SITE_LISPDIR%%/cask.el \
		%%EMACS_SITE_LISPDIR%%/cask-bootstrap.el \
		%%EMACS_SITE_LISPDIR%%/cask-cli.el \
		%%EMACS_SITE_LISPDIR%%/package-legacy.el \
		%%EMACS_SITE_LISPDIR%%/templates/init.tpl \
		%%EMACS_SITE_LISPDIR%%/templates/init-dev.tpl \
		bin/cask

post-patch:
	@${REINPLACE_CMD} -e 's|os.path.dirname(CASK_BIN_DIRECTORY)|"${PREFIX}/${EMACS_SITE_LISPDIR}"|' \
	    ${WRKSRC}/bin/cask

do-install:
	cd ${WRKSRC} && ${INSTALL_DATA} \
	    ${PLIST_FILES:M*.el:T} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/templates
	cd ${WRKSRC}/templates && ${INSTALL_DATA} ${PLIST_FILES:M*.tpl:T} \
	    ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/templates
	${INSTALL_SCRIPT} ${WRKSRC}/bin/cask \
	    ${STAGEDIR}${PREFIX}/bin/cask

.include <bsd.port.mk>
