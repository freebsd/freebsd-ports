# New ports collection makefile for:	MB-Ruby
# Date created:		23 March 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	musicbrainz
PORTVERSION=	0.2.0
CATEGORIES=	audio ruby
MASTER_SITES=	http://www.pablotron.org/download/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	mb-ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	MusicBrainz bindings for Ruby

LIB_DEPENDS=	musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/examples/*.rb

INSTALL_TARGET=	site-install

DOCS=		COPYING ChangeLog README TODO

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${CP} -R ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
