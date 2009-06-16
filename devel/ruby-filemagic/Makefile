# New ports collection makefile for:	Ruby/filemagic
# Date created:		29 July 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	filemagic
PORTVERSION=	0.1.1
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	http://grub.ath.cx/filemagic/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby binding to libmagic(3)

LIB_DEPENDS=	magic.1:${PORTSDIR}/sysutils/file

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

RUBY_RD_FILES=	filemagic.rd
DOCS=		AUTHORS CHANGELOG README TODO \
		${RUBY_RD_FILES} \
		${RUBY_RD_HTML_FILES}

.include <bsd.port.pre.mk>

post-install: doc-install

doc-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
