# $FreeBSD$

PORTNAME=	dash.el
PORTVERSION=	2.16.0
PORTREVISION=	1
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	Modern list library for Emacs

LICENSE=	GPLv3

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	magnars

NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	${EMACS_SITE_LISPDIR}/dash.el \
		${EMACS_SITE_LISPDIR}/dash-functional.el

do-install:
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PLIST_FILES:M*.el:T} \
	    ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR})

.include <bsd.port.mk>
