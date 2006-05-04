# New ports collection makefile for:	byaccr
# Date created:		2 Nov 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	byaccr
PORTVERSION=	0.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://ttsky.net/src/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Parser generator for ruby based on 'Berkeley Yacc' and 'Berkeley Yacc for Java'

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

DOCS=		README		README.html

post-patch:
	${REINPLACE_CMD} 's,^#include <malloc\.h>,#include <stdlib.h>,' ${WRKSRC}/*.[ch]

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
