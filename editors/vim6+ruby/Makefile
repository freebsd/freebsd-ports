# New ports collection makefile for:	VIM6 with embedded Ruby interpreter
# Date created:		22 Sep 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

MASTERDIR=	${.CURDIR}/../vim6

CATEGORIES=	editors ruby
PKGNAMESUFFIX=	+ruby
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	knu
PATCHFILES=	${PORTNAME}-${PORTVERSION}-if_ruby-missing-1.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	knu@FreeBSD.org

MD5_FILE=	${.CURDIR}/distinfo
COMMENT=	${.CURDIR}/pkg-comment

USE_RUBY=	yes

USE_AUTOCONF=	yes
MAKE_ARGS=	CONF_OPT_RUBY="--enable-rubyinterp" RUBY="${RUBY}"

.include "${MASTERDIR}/Makefile"
