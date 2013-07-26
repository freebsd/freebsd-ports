# New ports collection makefile for:	atanks
# Date created:			10 June 2010
# Whom:				Jesse Smith <jessefrgsmith@yahoo.ca>
#
# $FreeBSD$
#

PORTNAME=	atanks
PORTVERSION=	5.1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME}

MAINTAINER=	jessefrgsmith@yahoo.ca
COMMENT=	A 2D tank game with large, cartoonish weapons

LIB_DEPENDS=	alleg:${PORTSDIR}/devel/allegro

USE_GMAKE=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}/
PATCH_DEBUG=	1

.include <bsd.port.pre.mk>

post-patch:
		${REINPLACE_CMD} \
		    -e 's}^INSTALL[ 	]*=.*}INSTALL=${INSTALL} ${COPY}};' \
		    -e 's/-m *755/-m555 ${STRIP}/;' \
		    -e 's/-m *644/-m444/;' \
		    ${WRKSRC}/Makefile
.if ${OSVERSION} >= 800501
		${REINPLACE_CMD} \
		    -e 's/int Filter_File( struct dirent/int Filter_File( const struct dirent/' \
		    ${WRKSRC}/src/files.cpp
.endif

.include <bsd.port.post.mk>
