# New ports collection makefile for:	Ruby/GDChart
# Date created:		16 July 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$

PORTNAME=	gdchart
PORTVERSION=	0.0.9b
CATEGORIES=	graphics ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	ruby-gdchart/1080
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION:S/b$/-beta/}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby extension to use the GDCHART library

BROKEN=		Does not compile

BUILD_DEPENDS=	${LOCALBASE}/lib/libgdc.a:${PORTSDIR}/graphics/gdchart

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CONFIGURE_ARGS=	--with-gd-include="${LOCALBASE}/include/gd"
INSTALL_TARGET=	site-install

DOCS=		ChangeLog README.en
EXAMPLES=	*_sample.rb

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
