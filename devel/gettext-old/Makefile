# New ports collection makefile for:   gettext
# Date created:        16 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	0.10.35
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gettext

MAINTAINER=	reg@FreeBSD.org

USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

PLIST_SUB=	LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

pre-configure:
	${RM} ${WRKSRC}/doc/gettext.info*

post-install:
	@install-info ${PREFIX}/info/gettext.info ${PREFIX}/info/dir
	${MKDIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/misc/po-mode.el \
		${PREFIX}/share/emacs/site-lisp/po-mode.el
	${MKDIR} ${X11BASE}/share/locale

.include <bsd.port.mk>
