# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rbbr
PORTVERSION=	0.6.0
PORTREVISION=	11
CATEGORIES=	devel ruby
MASTER_SITES=	SF/ruby-gnome2/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	GTK+2-based Ruby module browser

BUILD_DEPENDS=	rubygem-gettext>=0:devel/rubygem-gettext
RUN_DEPENDS=	rubygem-gettext>=0:devel/rubygem-gettext \
		rubygem-gtk2>=0:x11-toolkits/rubygem-gtk2

BROKEN_RUBY22=	yes
BROKEN_RUBY23=	yes

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
USES=		gettext
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb

DOCS_EN=	AUTHORS COPYING ChangeLog README
DOCS_JA=	COPYING.ja README.ja

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS_EN} ${STAGEDIR}${RUBY_MODDOCDIR}/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS_JA} ${STAGEDIR}${RUBY_MODDOCDIR}/ja/

.include <bsd.port.mk>
