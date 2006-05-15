# New ports collection makefile for:	Ruby GetText Package
# Date created:		4 February 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	0.8.0
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.dvo.ru/pub/Gentoo/distfiles/ \
		ftp://ftp.tu-ilmenau.de/Mirrors/gentoo/distfiles/ \
		ftp://ftp.tugraz.at/ftp.tu-graz.ac.at/.mirror-sites/gentoo.inode.at/source/distfiles/ \
		ftp://mir1.ovh.net/gentoo-distfiles/distfiles/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-package-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Ruby implementation of the gettext library

BUILD_DEPENDS=	racc:${PORTSDIR}/devel/ruby-racc

USE_GETTEXT=	yes
USE_RUBY=	yes
USE_RUBY_FEATURES=	racc-runtime
USE_RUBY_SETUP=	yes

RUBY_SHEBANG_FILES=	bin/rgettext ${WRKSRC}/samples/*.rb

DOCS_EN=	ChangeLog README
DOCS_JA=	README.ja

.include <bsd.port.pre.mk>

post-install: doc-install

doc-install:
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/samples; ${RUBY} makemo.rb
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/samples/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.post.mk>
