# New ports collection makefile for:	VIM6 with embedded Ruby interpreter
# Date created:		22 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../vim6

CATEGORIES=	editors ruby
PKGNAMESUFFIX=	+ruby

MAINTAINER=	knu@FreeBSD.org

COMMENT=	${.CURDIR}/pkg-comment

USE_RUBY=	yes

MAKE_ARGS=	CONF_OPT_RUBY="--enable-rubyinterp" RUBY="${RUBY}"

.include "${MASTERDIR}/Makefile"
