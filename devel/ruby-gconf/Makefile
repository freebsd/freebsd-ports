# New ports collection makefile for:	ruby-gconf
# Date created:		20 October 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gconf
PORTVERSION=	0.2
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ruby-gnome
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

LIB_DEPENDS=	gconf-gtk-1.1:${PORTSDIR}/devel/gconf

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_GTK=	yes

CONFIGURE_ARGS=	--with-gtk-config=${GTK_CONFIG}
INSTALL_TARGET=	site-install

DOCS=	CREDITS \
	ChangeLog \
	INSTALL \
	Makefile \
	README \
	README.DEV \
	TODO

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/${PORTNAME}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/${PORTNAME}/
.endfor
.endif

.include <bsd.port.mk>
