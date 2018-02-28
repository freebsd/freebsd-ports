# $FreeBSD$

PORTNAME=	web-mode
PORTVERSION=	15.1
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Autonomous Emacs major-mode for editing web templates

LICENSE=	GPLv2

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	fxbois

MAKEFILE=	${FILESDIR}/Makefile
MAKE_ENV=	EMACS="${EMACS_CMD}" LISPDIR="${WEBMODE_LISPDIR}" \
		DESTDIR="${STAGEDIR}"
SUB_FILES=	web-mode-autoloads.el
SUB_LIST=	LISPDIR="${WEBMODE_LISPDIR}"
WEBMODE_LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/web-mode
PLIST_FILES=	${EMACS_VERSION_SITE_LISPDIR}/web-mode/web-mode.elc.gz \
		${EMACS_VERSION_SITE_LISPDIR}/web-mode-autoloads.el

post-install:
	${INSTALL_DATA} ${WRKDIR}/web-mode-autoloads.el \
	    ${STAGEDIR}${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

.include <bsd.port.mk>
