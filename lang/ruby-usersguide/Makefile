# New ports collection makefile for:	ruby-usersguide
# Date created:			30 Aug 2000
# Whom:				Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ruby-usersguide
PORTVERSION=	${VERSION}
PORTREVISION=	1
CATEGORIES+=	lang ruby
MASTER_SITES?=	http://www.cs.iastate.edu/~slagell/ruby/
DISTNAME?=	${SHORTNAME}-${VERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

SHORTNAME=	${PORTNAME:S/usersguide/uguide/}
VERSION?=	20000917

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes
RUBY_NO_RUN_DEPENDS=	yes

WRKSRC=		${WRKDIR}/${SHORTNAME}
NO_BUILD=	yes
PLIST_SUB=	LANGSUFFIX="${LANGSUFFIX}"

DOCDIR=		${RUBY_DOCDIR}/${PORTNAME}${LANGSUFFIX}

post-extract:
	if [ -f ${WRKSRC}/ansi.com ]; then ${RM} ${WRKSRC}/ansi.com; fi

do-install:
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${DOCDIR}
	${LN} -fs uguide00.html ${DOCDIR}/index.html

.include <bsd.port.mk>
