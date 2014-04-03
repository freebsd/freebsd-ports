# Created by: stas
# $FreeBSD$

PORTNAME=	ri-emacs
PORTVERSION=	0.2.3
CATEGORIES=	devel ruby elisp
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs extension to work with RDoc ri documentation

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

EMACSLISPDIR=	${PREFIX}/share/emacs/site-lisp
XEMACSLISPDIR=	${PREFIX}/lib/xemacs/site-lisp

SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_ELISPDIR}
	${INSTALL_DATA} ${WRKSRC}/ri-ruby.el ${STAGEDIR}${RUBY_ELISPDIR}
	@${MKDIR} ${STAGEDIR}${XEMACSLISPDIR}
	${LN} -sf ${RUBY_ELISPDIR}/ri-ruby.el ${STAGEDIR}${EMACSLISPDIR}
	${LN} -sf ${RUBY_ELISPDIR}/ri-ruby.el ${STAGEDIR}${XEMACSLISPDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ri-emacs.rb ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
