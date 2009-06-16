# New ports collection makefile for:	Ruby/OpenGL
# Date created:		24 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	opengl
PORTVERSION=	0.32b
PORTREVISION=	4
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www2.giganet.net/~yoshi/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rbogl-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	OpenGL/GLU/GLUT interface modules for Ruby

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_GL=		glut

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-ruby-dir="${LOCALBASE}" --with-x11-dir="${LOCALBASE}"
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${RUBY_MODDOCDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.EUC ${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
