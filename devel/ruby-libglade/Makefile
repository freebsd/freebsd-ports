# New ports collection makefile for:	Ruby-libglade
# Date created:		8 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libglade
PORTVERSION=	1.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://beta4.com/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	glade.4:${PORTSDIR}/devel/libglade
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
WANT_GLIB=	yes
WANT_GTK=	yes

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}
CONFIGURE_ARGS=	--with-glade-include="${LOCALBASE}/include/glade" \
		--with-glib-config="${GLIB_CONFIG}" \
		--with-gtk-config="${GTK_CONFIG}"
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/libglade/
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/libglade/
	${MKDIR} ${RUBY_DOCDIR}/libglade
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/libglade/
.endif

.include <bsd.port.mk>
