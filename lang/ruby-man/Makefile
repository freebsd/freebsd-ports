# New ports collection makefile for:	ruby-man
# Date created:			Sat Aug 17 17:10:02 CEST 2000
# Whom:				olgeni@uli.it
#
# $FreeBSD$
#

PORTNAME=	ruby-man
PORTVERSION=	1.4.6
CATEGORIES+=	lang ruby
MASTER_SITES=	ftp://ftp.netlab.co.jp/pub/lang/ruby/doc/
DISTNAME=	${PORTNAME}-${PORTVERSION}${LANGSUFFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	olgeni@uli.it

PLIST_SUB=	RUBY_VER="${RUBY_VER}" LANGSUFFIX="${LANGSUFFIX}"

RUBY_VER?=	1.4
WRKSRC=		${WRKDIR}/${PORTNAME}-${RUBY_VER}${LANGSUFFIX}

NO_BUILD=	yes

DOCDIR=		${PREFIX}/share/doc/ruby/ruby-man-${RUBY_VER}${LANGSUFFIX}

do-install:
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCDIR}

.include <bsd.port.mk>
