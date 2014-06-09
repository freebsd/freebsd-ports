# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	freedb
PORTVERSION=	0.5
CATEGORIES=	audio net ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library that provides access to Freedb/CDDB servers

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

INSTALL_TARGET=	site-install

DOCS=		CHANGELOG	README	doc
EXAMPLES=	examples/*.rb

post-patch:
	${REINPLACE_CMD} -E -e "s,RSTRING\(([^)]+)\)->ptr,RSTRING_PTR(\1),g" ${WRKSRC}/freedb_cdrom.c

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${EXAMPLES:S,^,${WRKSRC}/,} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	@(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "${DOCS}" ${STAGEDIR}${RUBY_MODDOCDIR}/)

.include <bsd.port.mk>
