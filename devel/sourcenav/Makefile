# New ports collection makefile for:	sourcenav
# Date created:			23 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	sourcenav
PORTVERSION=	5.1.4
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Source code analysis tool

LIB_DEPENDS=	tcl83.1:${PORTSDIR}/lang/tcl83 \
		tk83.1:${PORTSDIR}/x11-toolkits/tk83

.if defined(PREFIX)
PREFIX:=	${PREFIX}/${PORTNAME}
.else
PREFIX?=	${LOCALBASE}/${PORTNAME}
.endif
USE_BISON=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
GNU_CONFIGURE=	yes
NO_MTREE=	yes

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
