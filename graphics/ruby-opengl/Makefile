# New ports collection makefile for:	Ruby/OpenGL
# Date created:		24 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	opengl
PORTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www2.giganet.net/~yoshi/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rbogl
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_MESA=	yes

WRKSRC=		${WRKDIR}/oglmodule
CONFIGURE_ARGS=	--with-ruby-dir="${LOCALBASE}" --with-x11-dir="${X11BASE}"
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/opengl
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_EXAMPLESDIR}/opengl/
	${MKDIR} ${RUBY_DOCDIR}/opengl/ja
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${RUBY_DOCDIR}/opengl/
	${INSTALL_DATA} ${WRKSRC}/README.EUC ${RUBY_DOCDIR}/opengl/ja/
.endif

.include <bsd.port.mk>
