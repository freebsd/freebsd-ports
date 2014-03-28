# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rbbr
PORTVERSION=	0.6.0
PORTREVISION=	11
CATEGORIES=	devel ruby
MASTER_SITES=	SF/ruby-gnome2/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/rev/}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A GTK+2-based Ruby module browser

BUILD_DEPENDS=	rubygem-gettext>0:${PORTSDIR}/devel/rubygem-gettext
RUN_DEPENDS=	rubygem-gtk2>0:${PORTSDIR}/x11-toolkits/rubygem-gtk2 \
		rubygem-gettext>0:${PORTSDIR}/devel/rubygem-gettext

USES=		gettext
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
NO_STAGE=	yes

DOCS_EN=	AUTHORS COPYING ChangeLog README
DOCS_JA=	COPYING.ja README.ja

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${RUBY_MODDOCDIR}/ja
.for f in ${DOCS_EN}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.for f in ${DOCS_JA}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/ja/
.endfor
.endif

.include <bsd.port.mk>
