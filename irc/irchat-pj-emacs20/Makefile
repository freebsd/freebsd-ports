# New ports collection makefile for:	irchat-pj (for emacs20)
# Date Created:		2 May 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	irchat-pj
PORTVERSION=	2.5.6
CATEGORIES=	irc elisp
MASTER_SITES=	ftp://ftp.fan.gr.jp/pub/elisp/irchat-pj/2.5/%SUBDIR%/
MASTER_SITE_SUBDIR=	. OLD
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	irchat-pj-${PORTVERSION}p

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	irchat-pj-2.5.6pl1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	yoichi@eken.phys.nagoya-u.ac.jp

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/pure/pure-make.el:${PORTSDIR}/irc/pure-${EMACS_PORT_NAME}
RUN_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/pure/pure-make.el:${PORTSDIR}/irc/pure-${EMACS_PORT_NAME} \
		${LOCALBASE}/bin/dcc:${PORTSDIR}/irc/dcc

EMACS_PORT_NAME?=	emacs20
XEMACS_ONLY?=	"@comment "
LISPDIR?=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
ETCDIR=		share/doc/${PORTNAME}

MAKE_ARGS+=	LISPDIR=${PREFIX}/${LISPDIR} \
		PACKDIR=${PREFIX}/${EMACS_LIBDIR}/site-packages

DOCS=		README.25 doc24/CHANGELOG doc24/FAQ-about-jp24.txt\
		doc24/FAQ-irchat-PJ.txt doc24/INSTALL.irchat-pj\
		doc24/README.browse-url-plus doc24/README.irchat-pj\
		doc24/browse-url-plus-init.el doc24/dot.irchat_vars.el

PLIST_SUB=	LISPDIR=${LISPDIR} \
		ETCDIR=${ETCDIR} \
		XEMACS_ONLY=${XEMACS_ONLY}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${ETCDIR}
.for f in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/${f} ${PREFIX}/${ETCDIR}
.endfor
.endif

.include <bsd.port.mk>
