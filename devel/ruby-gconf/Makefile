# New ports collection makefile for:	ruby-gconf
# Date created:		20 October 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gconf
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ruby-gnome
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby interface to GConf (1.0.x)

LIB_DEPENDS=	gconf-gtk-1.1:${PORTSDIR}/devel/gconf

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_GNOME=	gtk12

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
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
