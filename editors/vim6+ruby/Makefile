# New ports collection makefile for:	VIM6 with embedded Ruby interpreter
# Date created:		22 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../vim6

CATEGORIES=	editors ruby
PKGNAMESUFFIX=	+ruby
PATCH_SITES=	http://www.ruby-lang.org/~shugo/vim-ruby/
PATCHFILES=	${PORTNAME}-${PORTVERSION}-if_ruby-2.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	knu@FreeBSD.org

MD5_FILE=	${.CURDIR}/distinfo
COMMENT=	${.CURDIR}/pkg-comment

USE_RUBY=	yes

USE_AUTOCONF=	yes
MAKE_ARGS=	CONF_OPT_RUBY="--enable-rubyinterp" RUBY="${RUBY}"

post-install:	add-plist

add-plist:
	( \
	${ECHO} "/if_python.txt$$/"; \
	${ECHO}	"t"; \
	${ECHO} "s/python/ruby/"; \
	${ECHO} "w"; \
	${ECHO} "q"; \
	) | ed ${TMPPLIST}

.include "${MASTERDIR}/Makefile"
