# New ports collection makefile for:	emacs20-dl-wnn6
# Version required:	0.2.2
# Date created:		10 October 1998
# Whom:			shige
#
# $Id: Makefile,v 1.1.1.1 1999/01/11 14:21:24 kuriyama Exp $
#

DISTNAME=	dl-wnn-0.2.2
PKGNAME=	ja-emacs20-dl-wnn6-0.2.2
CATEGORIES=	japanese editors
MASTER_SITES=	http://tt-www.cs.titech.ac.jp/~katsuya/emacs/

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

LIB_DEPENDS=	wnn6.1:${.CURDIR}/../../japanese/Wnn6-lib
BUILD_DEPENDS=	emacs-dl-${EMACS_VER}:${EMACSDL_DIR} \
		/nonexistent:${EMACSDL_DIR}:configure
RUN_DEPENDS=	emacs-dl-${EMACS_VER}:${EMACSDL_DIR}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wnn-includes=${PREFIX}/include/wnn --with-wnn6 \
		--with-emacs-src=${WRKDIRPREFIX}${EMACSDL_DIR}/work/emacs-${EMACS_VER}
CONFIGURE_ENV=	EMACS=emacs-dl-${EMACS_VER}
PLIST_SUB=	EMACS_VER=${EMACS_VER} DOCDIR=${DOCDIR}

DOCDIR=		share/doc/emacs20-dl-wnn6
EMACS_VER=	20.3
EMACSDL_DIR=	${.CURDIR}/../../editors/emacs20-dl

post-install:
	@${LN} ${PREFIX}/share/emacs/site-lisp/egg/eggrc-wnn \
		${PREFIX}/share/emacs/site-lisp/egg/.eggrc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.jp ${PREFIX}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/${DOCDIR}
.endif

.include <bsd.port.mk>
