# ex: ts=8
# New ports collection makefile for:	sourcenav
# Date created:			23 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	sourcenav
DISTVERSION=	6.0
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
CONFIGURE_ARGS=	--prefix=${PREFIX}
NO_MTREE=	yes

.include "Makefile.man"

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|-fwritable-strings||g' \
	    ${WRKSRC}/snavigator/configure \
	    ${WRKSRC}/tix/unix/tk8.3/Makefile.in
	${REINPLACE_CMD} -e 's|/bin/sed|/usr/bin/sed|g' \
	    ${WRKSRC}/db4/PORT/libtool

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
