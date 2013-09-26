# Created by: Alan Eldridge <alane@geeksrus.net>
# $FreeBSD$

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

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

USE_RUBY=		yes
USE_RUBY_EXTCONF=	yes
INSTALL_TARGET=		site-install

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
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
