# New ports collection makefile for:	rbbr
# Date created:		24 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rbbr
PORTVERSION=	0.6.0
PORTREVISION=	7
CATEGORIES=	devel ruby
MASTER_SITES=	SF/ruby-gnome2/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/rev/}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A GTK+2-based Ruby module browser

BUILD_DEPENDS=	${RUBY_SITELIBDIR}/gettext.rb:${PORTSDIR}/devel/ruby-gettext
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${RUBY_SITELIBDIR}/gettext.rb:${PORTSDIR}/devel/ruby-gettext

USE_GETTEXT=	yes
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS_EN=	AUTHORS COPYING ChangeLog README
DOCS_JA=	COPYING.ja README.ja

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
