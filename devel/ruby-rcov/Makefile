# Created by: Rui Lopes (rgl ruilopes com)
# $FreeBSD$

PORTNAME=	rcov
PORTVERSION=	0.8.1.2
CATEGORIES=	devel ruby
MASTER_SITES=	RF
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A tool for simple code coverage analysis in Ruby

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-10-10

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

DOC_FILES=	BLURB CHANGES LEGAL LICENSE README.API \
		README.en README.rake README.rant THANKS
EXAMPLE_FILES=	Rakefile Rantfile

# make sure setup.rb honours $PREFIX
NO_STAGE=	yes
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

.include <bsd.port.pre.mk>
.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif
.include <bsd.port.post.mk>
