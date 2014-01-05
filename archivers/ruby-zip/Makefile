# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	zip
PORTVERSION=	0.9.4
CATEGORIES=	archivers ruby
MASTER_SITES=	SF/ruby${PORTNAME}/ruby${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby module for reading and writing ZIP files

USE_RUBY=	yes
USE_RUBY_FEATURES=	zlib

WRKSRC=		${WRKDIR}/rubyzip-${PORTVERSION}
NO_BUILD=	yes

DOCS=		ChangeLog NEWS README TODO
EXAMPLES=	samples/*

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/zip
	${INSTALL_DATA} ${WRKSRC}/lib/zip/*.rb ${STAGEDIR}${RUBY_SITELIBDIR}/zip
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
