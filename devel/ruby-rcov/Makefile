# Ports collection makefile for:	rcov
# Date created:				25 May 2006
# Whom:					Rui Lopes (rgl ruilopes com)
#
# $FreeBSD$
#

PORTNAME=	rcov
PORTVERSION=	0.8.0.2
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A tool for simple code coverage analysis in Ruby

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOC_FILES=	BLURB CHANGES LEGAL LICENSE README.API \
		README.en README.rake README.rant THANKS
EXAMPLE_FILES=	Rakefile Rantfile

# make sure setup.rb honours $PREFIX
post-configure:
	@${REINPLACE_CMD} -E 's,^([^r].+=)${LOCALBASE}(.*)$$,\1${PREFIX}\2,g' ${WRKSRC}/.config

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${RUBY_MODEXAMPLESDIR:S,^${LOCALBASE},${PREFIX},}
	${MKDIR} ${RUBY_MODDOCDIR:S,^${LOCALBASE},${PREFIX},}
.for f in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR:S,^${LOCALBASE},${PREFIX},}
.endfor
.for f in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR:S,^${LOCALBASE},${PREFIX},}
.endfor
.endif

.include <bsd.port.mk>
