# New ports collection makefile for:	rubyzip
# Date created:		26 January 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	zip
PORTVERSION=	0.4.2
CATEGORIES=	archivers ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ruby${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/zlib.so:${PORTSDIR}/archivers/ruby-zlib

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/ruby${PORTNAME}
NO_BUILD=	yes

DOCS=		ChangeLog NEWS README TODO
EXAMPLES=	example.rb NEWS		# NEWS is used as test data

do-install:
	${INSTALL_DATA} ${WRKSRC}/zip.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
