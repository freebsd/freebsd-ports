# New ports collection makefile for:	sourcenav
# Date created:			23 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	sourcenav
PORTVERSION=	5.1.4
PORTREVISION=	9
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Source code analysis tool

.if defined(PREFIX)
PREFIX:=	${PREFIX}/${PORTNAME}
.else
PREFIX?=	${LOCALBASE}/${PORTNAME}
.endif
USE_BISON=	build
USE_GMAKE=	yes
USE_XORG=	x11 xext xpm
GNU_CONFIGURE=	yes
NO_MTREE=	yes
USE_TCL=	83
USE_TK=		83

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
EXTRA_PATCHES+=	${FILESDIR}/FreeBSD6-cdefs.h
.endif

post-install:
	@${LN} -s ${PREFIX}/bin/snavigator ${PREFIX}/../bin
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
