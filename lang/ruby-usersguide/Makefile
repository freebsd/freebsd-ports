# New ports collection makefile for:	ruby-usersguide
# Date created:			30 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ruby-usersguide
PORTVERSION=	${VERSION}
CATEGORIES+=	lang ruby
MASTER_SITES?=	http://www.cs.iastate.edu/~slagell/ruby/
DISTNAME?=	${SHORTNAME}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

SHORTNAME=	${PORTNAME:S/usersguide/uguide/}
VERSION?=	20000904

PLIST_SUB=	RUBY_VER="${RUBY_VER}" LANGSUFFIX="${LANGSUFFIX}"

WRKSRC=		${WRKDIR}/${SHORTNAME}

NO_BUILD=	yes

DOCDIR=		${PREFIX}/share/doc/ruby/${PORTNAME}${LANGSUFFIX}

post-extract:
	if [ -f ${WRKSRC}/ansi.com ]; then ${RM} ${WRKSRC}/ansi.com; fi

do-install:
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${DOCDIR}
	${LN} -fs uguide00.html ${DOCDIR}/index.html

.include <bsd.port.mk>
