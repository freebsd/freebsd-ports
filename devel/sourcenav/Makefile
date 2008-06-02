# New ports collection makefile for:	sourcenav
# Date created:			23 July 2000
# Whom:				Donald Burr <dburr@FreeBSD.ORG>
#
# $FreeBSD$
#

PORTNAME=	sourcenav
DISTVERSION=	5.2b2
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

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|-fwritable-strings||g' \
	    ${WRKSRC}/snavigator/configure \
	    ${WRKSRC}/tix/unix/tk8.3/Makefile.in

post-install:
	@${LN} -s ${PREFIX}/bin/snavigator ${PREFIX}/../bin
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.post.mk>
