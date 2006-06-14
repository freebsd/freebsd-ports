# Ports collection makefile for:	rcov
# Date created:				25 May 2006
# Whom:					Rui Lopes (rgl ruilopes com)
#
# $FreeBSD$
#

PORTNAME=	rcov
PORTVERSION=	0.5.0
CATEGORIES=	devel ruby
MASTER_SITES=	http://eigenclass.org/static/rcov/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	rgl@ruilopes.com
COMMENT=	A tool for simple code coverage analysis in Ruby

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOC_FILES=	BLURB CHANGES LEGAL LICENSE README.API \
		README.en README.rake README.rant THANKS
EXAMPLE_FILES=	Rakefile Rantfile

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${RUBY_MODEXAMPLESDIR} ${RUBY_MODDOCDIR}
.for f in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}
.endfor
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}
.endfor
.endif

.include <bsd.port.mk>
