# New ports collection makefile for:		ruby-dbdbd
# Date created:					08 December 2004
# Whom:						Brooks Davis <brooks@aero.org>
#
# $FreeBSD$
#

PORTNAME=	dbdbd
PORTVERSION=	0.2.2
CATEGORIES=	databases ruby
MASTER_SITES=	http://knossos.shu.edu/dblack/dbdbd/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	David Black's DataBase Definer

NO_PACKAGE=	License only allows unchanged distributions

USE_RUBY=	yes
NO_BUILD=	yes

# DOCS
DOCS=		ChangeLog doc/README doc/README.html
# EXAMPLES relative to samples subdir
EXAMPLES=	movies.rb movies.txt phonebook.rb phonebook.txt

PLIST_FILES=	%%RUBY_SITELIBDIR%%/dbdbd.rb \
		${EXAMPLES:C;^;%%RUBY_MODEXAMPLESDIR%%/;}
PLIST_DIRS=	%%RUBY_MODEXAMPLESDIR%%
.if !defined(NOPORTDOCS)
PLIST_FILES+=	${DOCS:C;^;%%RUBY_MODDOCDIR%%/;:C;doc/;;}
PLIST_DIRS+=	%%RUBY_MODDOCDIR%%
.endif

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/dbdbd.rb ${RUBY_SITELIBDIR}
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
