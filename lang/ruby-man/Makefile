# New ports collection makefile for:	ruby-man
# Date created:			Sat Aug 17 17:10:02 CEST 2000
# Whom:				olgeni@uli.it
#
# $FreeBSD$
#

PORTNAME=	ruby-man
PORTVERSION=	1.4.6
CATEGORIES+=	lang ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	doc
DISTNAME=	${PORTNAME}-${PORTVERSION}${LANGSUFFIX}

MAINTAINER=	olgeni@uli.it

DIST_SUBDIR=	ruby

PLIST_SUB=	LANGSUFFIX="${LANGSUFFIX}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}${LANGSUFFIX}

NO_BUILD=	yes

DOCDIR=		${RUBY_DOCDIR}/ruby-man${LANGSUFFIX}

do-install:
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DOCDIR}

.include <bsd.port.mk>
