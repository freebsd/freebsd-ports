# New ports collection makefile for:	Ruby-libglade
# Date created:		8 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	libglade
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	devel ruby gnome
MASTER_SITES=	http://beta4.com/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION:S/./-/g}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk
LIB_DEPENDS=	glade.4:${PORTSDIR}/devel/libglade

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_GNOME=	yes

WRKSRC=		${WRKDIR}/ruby-${PORTNAME}
CONFIGURE_ARGS=	--with-glade-include="${LOCALBASE}/include/glade" \
		--with-glib-config="${GLIB_CONFIG}" \
		--with-gtk-config="${GTK_CONFIG}"
INSTALL_TARGET=	site-install

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/${PORTNAME}/
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/${PORTNAME}/
.endif

.include <bsd.port.mk>
