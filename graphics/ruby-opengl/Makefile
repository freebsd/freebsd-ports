# New ports collection makefile for:	Ruby/OpenGL
# Date created:		24 Aug 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	opengl
PORTVERSION=	0.32b
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www2.giganet.net/~yoshi/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	rbogl-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

USE_MESA=	yes

RUBY_WITH_PTHREAD=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
CONFIGURE_ARGS=	--with-ruby-dir="${LOCALBASE}" --with-x11-dir="${X11BASE}"
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}/ja
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${RUBY_DOCDIR}/${PORTNAME}/
	${INSTALL_DATA} ${WRKSRC}/README.EUC ${RUBY_DOCDIR}/${PORTNAME}/ja/
.endif

.include <bsd.port.mk>
