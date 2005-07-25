# New ports collection makefile for:	ruby-gdk_imlib
# Date created:		28 February 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gdk_imlib
PORTVERSION=	${RUBY_GNOME_PORTVERSION}
PORTREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	${RUBY_GNOME_MASTER_SITES}
MASTER_SITE_SUBDIR=	${RUBY_GNOME_MASTER_SITE_SUBDIR}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${RUBY_GNOME_DISTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby binding for Gdk-imlib

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk.so:${PORTSDIR}/x11-toolkits/ruby-gtk

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
USE_XLIB=	yes
USE_GNOME=	imlib

SLAVE_PORT=	yes
MASTER_PORT=	x11/ruby-gnome

.include "${.CURDIR}/../../x11/ruby-gnome/Makefile.common"

WRKSRC=		${RUBY_GNOME_WRKSRC}/${PORTNAME}
INSTALL_TARGET=	site-install
CONFIGURE_ARGS=	--with-imlib-config="${IMLIB_CONFIG}"

DOCS_EN=	ChangeLog

post-extract:
	${MV} ${WRKSRC:S/gdk_imlib$/gdkimlib/} ${WRKSRC}
	${FIND} ${WRKSRC} -type d -name CVS -print0 | ${XARGS} -0 ${RM} -r

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
