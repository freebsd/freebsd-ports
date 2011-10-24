# New ports collection makefile for:	ri-emacs
# Date created:		16 June 2009
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	ri-emacs
PORTVERSION=	0.2.3
CATEGORIES=	devel ruby elisp
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An emacs extension to work with RDoc ri documentation

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

ELISP_FILES=	ri-ruby.el
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${RUBY_ELISPDIR}/
	${INSTALL_DATA} ${ELISP_FILES:S,^,${WRKSRC}/,} ${RUBY_ELISPDIR}/
	${MKDIR} ${XEMACSLISPDIR}
.for f in ${ELISP_FILES}
	${LN} -sf ${RUBY_ELISPDIR}/${f} ${EMACSLISPDIR}/
	${LN} -sf ${RUBY_ELISPDIR}/${f} ${XEMACSLISPDIR}/
.endfor
	${MKDIR} ${DATADIR}/
	${INSTALL_DATA} ${WRKSRC}/ri-emacs.rb ${DATADIR}/
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
