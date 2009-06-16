# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	ruby-jttui
# Date created:		2003-02-12
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	jttui
PORTVERSION=	200205082055
PORTREVISION=	0
PORTEPOCH=	0
CATEGORIES=	devel ruby
MASTER_SITES=	http://klokan.sh.cvut.cz/~jtra/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	jttui.${PORTVERSION}

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Textmode User Interface by Jakub Travnik

USE_RUBY=		yes
USE_RUBY_EXTCONF=	yes
INSTALL_TARGET=		site-install

.include <bsd.port.pre.mk>
post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
	cd ${WRKSRC}/doc; \
	${FIND} . | ${CPIO} -pdmv ${RUBY_MODDOCDIR}
	${CHMOD} -R ugo+rX,ugo-w ${RUBY_MODDOCDIR}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}
	${CHMOD} ugo+x ${RUBY_MODEXAMPLESDIR}/example-*.rb
.endif # !defined(NOPORTDOCS)
.include <bsd.port.post.mk>
