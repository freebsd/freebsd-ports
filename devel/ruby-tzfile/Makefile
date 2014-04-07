# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	tzfile
PORTVERSION=	0.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://www.a-k-r.org/ruby-tzfile/
DISTFILES=	ruby-${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	TZFile handling library for Ruby

OPTIONS_DEFINE=	DOCS

USE_RUBY=	yes

NO_BUILD=	yes

RUBY_RD_FILES=	tzfile.rb

WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=		${RUBY_RD_HTML_FILES}

do-install:
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/
	${INSTALL_DATA} ${WRKSRC}/tzfile.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
