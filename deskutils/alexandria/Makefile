# New ports collection makefile for:	Alexandria
# Date created:		18 March 2005
# Whom:			Mitsuru YOSHIDA <mitsuru@riken.jp>
#
# $FreeBSD$
#

PORTNAME=	alexandria
PORTVERSION=	0.6.1
PORTREVISION=	10
CATEGORIES=	deskutils ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	mitsuru@riken.jp
COMMENT=	A GNOME application to help you manage your book collection

RUN_DEPENDS=	${RUBY_SITELIBDIR}/amazon.rb:${PORTSDIR}/www/ruby-amazon \
		${RUBY_SITELIBDIR}/gettext.rb:${PORTSDIR}/devel/ruby-gettext \
		${RUBY_SITEARCHLIBDIR}/libglade2.so:${PORTSDIR}/devel/ruby-libglade2 \
		${RUBY_SITEARCHLIBDIR}/gnome2.so:${PORTSDIR}/x11/ruby-gnome2 \
		${RUBY_SITEARCHLIBDIR}/gdk_pixbuf2.so:${PORTSDIR}/graphics/ruby-gdk_pixbuf2 \
		${RUBY_SITEARCHLIBDIR}/gconf2.so:${PORTSDIR}/devel/ruby-gconf2 \
		rubygem-zoom>=0:${PORTSDIR}/devel/rubygem-zoom

USE_GNOME=	gnomehier
INSTALLS_OMF=	yes
USE_GETTEXT=	yes
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS=		NEWS README TODO
GCONF_SCHEMAS=	alexandria.schemas

RUBY_REQUIRE=	Ruby > 180
CONFIGURE_ARGS=	"--prefix=${PREFIX}"

.include <bsd.port.pre.mk>

.if !defined(RUBY_PROVIDED)
IGNORE=		only works with Ruby 1.8.0 or later
.endif

post-install:
	@${MKDIR} ${LOCALBASE}/etc/gconf/schemas
	@${INSTALL_DATA} ${WRKSRC}/schemas/alexandria.schemas \
		${LOCALBASE}/etc/gconf/schemas/
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
