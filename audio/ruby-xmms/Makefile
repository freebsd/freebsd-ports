# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	xmms
PORTVERSION=	0.1.2
PORTREVISION=	3
CATEGORIES=	audio ruby
MASTER_SITES=	http://www.pablotron.org/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	XMMS bindings for Ruby

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

USE_RUBY=	yes
NO_STAGE=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS=		AUTHORS COPYING ChangeLog README doc

CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not compile with ruby 1.9
.endif
.include <bsd.port.post.mk>
