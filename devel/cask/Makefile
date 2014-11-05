# $FreeBSD$

PORTNAME=	cask
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	devel elisp
DISTNAME=	cask-v${PORTVERSION}

MAINTAINER=	rpaulo@FreeBSD.org
COMMENT=	Project management tool for Emacs

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	cask
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	3c0ca37
GH_PROJECT=	cask

USE_EMACS=	yes
USES=		python

NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|os.path.dirname(CASK_BIN_DIRECTORY)|"${PREFIX}/${EMACS_SITE_LISPDIR}"|' \
		${WRKSRC}/bin/cask

do-install:
	${INSTALL_DATA} ${WRKSRC}/cask.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cask-bootstrap.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/cask-cli.el \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/templates
	${INSTALL_DATA} ${WRKSRC}/templates/init.tpl \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/templates
	${INSTALL_DATA} ${WRKSRC}/templates/init-dev.tpl \
		${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/templates
	${INSTALL_SCRIPT} ${WRKSRC}/bin/cask \
		${STAGEDIR}${PREFIX}/bin/cask

.include <bsd.port.mk>
