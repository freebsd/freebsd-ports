# New ports collection makefile for:   gettext
# Version required:    0.10.35
# Date created:        16 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	gettext-0.10.35
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gettext

MAINTAINER=	nakai@FreeBSD.org

USE_LIBTOOL=	yes

PLIST_SUB=	X11BASE=${X11BASE}

pre-configure:
	${RM} ${WRKSRC}/doc/gettext.info*

post-install:
	@install-info ${PREFIX}/info/gettext.info ${PREFIX}/info/dir
	${INSTALL_DATA} ${WRKSRC}/misc/po-mode.el \
		${PREFIX}/share/gettext/po-mode.el
	${MKDIR} ${X11BASE}/share/locale

.include <bsd.port.mk>
