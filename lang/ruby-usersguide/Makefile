# New ports collection makefile for:	ruby-usersguide
# Date created:			30 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ruby-usersguide
PORTVERSION=	${VERSION}
CATEGORIES+=	lang ruby
MASTER_SITES?=	http://www.math.sci.hokudai.ac.jp/~gotoken/ruby/
DISTNAME=	${SHORTNAME}-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

SHORTNAME=	${PORTNAME:S/usersguide/uguide/}
VERSION?=	981227

PLIST_SUB=	RUBY_VER="${RUBY_VER}" LANGSUFFIX="${LANGSUFFIX}"

WRKSRC=		${WRKDIR}/${SHORTNAME}

NO_BUILD=	yes

DOCDIR=		${PREFIX}/share/doc/ruby/${PORTNAME}${LANGSUFFIX}

do-install:
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${WRKSRC}/uguide* ${DOCDIR}

.include <bsd.port.mk>
