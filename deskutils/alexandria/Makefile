# New ports collection makefile for:	Alexandria
# Date created:		18 March 2005
# Whom:			Mitsuru YOSHIDA <mitsuru@riken.jp>
#
# $FreeBSD$
#

PORTNAME=	alexandria
PORTVERSION=	0.6.1
PORTREVISION=	2
CATEGORIES=	deskutils ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	mitsuru@riken.jp
COMMENT=	A GNOME application to help you manage your book collection

RUN_DEPENDS=	${RUBY_SITELIBDIR}/amazon.rb:${PORTSDIR}/www/ruby-amazon \
		${RUBY_SITEARCHLIBDIR}/locale_system.so:${PORTSDIR}/devel/ruby-gettext \
		${RUBY_SITEARCHLIBDIR}/libglade2.so:${PORTSDIR}/devel/ruby-libglade2 \
		${RUBY_SITEARCHLIBDIR}/gnome2.so:${PORTSDIR}/x11/ruby-gnome2 \
		${RUBY_SITEARCHLIBDIR}/gdk_pixbuf2.so:${PORTSDIR}/graphics/ruby-gdk_pixbuf2 \
		${RUBY_SITEARCHLIBDIR}/gconf2.so:${PORTSDIR}/devel/ruby-gconf2

INSTALLS_OMF=	yes
USE_GETTEXT=	yes
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

RUBY_REQUIRE=	Ruby > 180
CONFIGURE_ARGS=	"--prefix=${PREFIX}"

.include <bsd.port.pre.mk>

.if !defined(RUBY_PROVIDED)
IGNORE=		only works with Ruby 1.8.0 or later
.endif

post-install:
	${RM} ${PREFIX}/share/gnome/help/alexandria/ChangeLog

.include <bsd.port.post.mk>
