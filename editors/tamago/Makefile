# Created by: tetsushi NAKAI <nakai@tsl.pe.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	tamago
PORTVERSION=	4.0.6.0.20041122.19.14
DISTVERSIONPREFIX=	v
PORTREVISION=	3
CATEGORIES=	editors elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Egg V4, Multilingual Input Method for Emacsen

LICENSE=	GPLv2

USES=		emacs
# Fails to build with Emacs 27.
# Temporarily disable devel_full and devel_nox.
EMACS_FLAVORS_EXCLUDE=	devel_full devel_nox
USE_GITHUB=	yes
GH_ACCOUNT=	hrs-allbsd

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lispdir="${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}"
CONFIGURE_ENV=	EMACS="${EMACS_CMD}"
PLIST_SUB=	ELISPDIR="${EMACS_VERSION_SITE_LISPDIR}"
PORTDOCS=	AUTHORS ChangeLog ChangeLog.1997-1998 \
		ChangeLog.2000-2001 ChangeLog.2002-2004 \
		PROBLEMS README README.ja.txt TODO egg-anthy.readme
OPTIONS_DEFINE=	DOCS
DOCS_CONFIGURE_ENABLE=	doc

.include <bsd.port.mk>
