# New ports collection makefile for:	rbbr
# Date created:		24 November 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	rbbr
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ruby-gnome2
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/rev/}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A GTK+2-based Ruby module browser

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2 \
		${RUBY_SITEARCHLIBDIR}/gdk_pixbuf2.so:${PORTSDIR}/graphics/ruby-gdk_pixbuf2 \
		${RUBY_ARCHLIBDIR}/gdbm.so:${PORTSDIR}/databases/ruby-gdbm \
		ri:${PORTSDIR}/lang/ruby-ri

USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS_EN=	AUTHORS \
		ChangeLog \
		README
DOCS_JA=	README.ja

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
