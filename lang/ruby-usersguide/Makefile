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
DISTNAME?=	${SHORTNAME}-${VERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

SHORTNAME=	${PORTNAME:S/usersguide/uguide/}
VERSION?=	20000915

PLIST_SUB=	LANGSUFFIX="${LANGSUFFIX}"

WRKSRC=		${WRKDIR}/${SHORTNAME}

NO_BUILD=	yes

DOCDIR=		${RUBY_DOCDIR}/${PORTNAME}${LANGSUFFIX}

post-extract:
	if [ -f ${WRKSRC}/ansi.com ]; then ${RM} ${WRKSRC}/ansi.com; fi

do-install:
	${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${DOCDIR}
	${LN} -fs uguide00.html ${DOCDIR}/index.html

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.ruby.mk"
.include <bsd.port.post.mk>
