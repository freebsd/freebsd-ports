# New ports collection makefile for:	ruby_r-devel
# Date created:			3 June 2001
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

MASTERDIR=      ${.CURDIR}/../ruby-devel

RUBY_VER=	1.8

BUILD_DEPENDS=	${RUBY_WITHOUT_SUFFIX}${RUBY_VER:S/.//}:${MASTERDIR}
RUN_DEPENDS=	${RUBY_WITHOUT_SUFFIX}${RUBY_VER:S/.//}:${MASTERDIR}

NOPORTDOCS=	yes
NORUBYLIB=	yes

RUBY_WITH_PTHREAD=	yes

.include "${MASTERDIR}/Makefile"
