# New ports collection makefile for:	id3lib
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	id3lib
PORTVERSION=	3.8.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PORTREVISION=	1

MAINTAINER=	ports@oven.org
COMMENT=	Library for manipulating ID3v1/v1.1 and ID3v2 tags

USE_ICONV=	yes
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

CC_BASENAME=	${CC:T}
# Should run ${CC} -v and check the output instead
.if ${CC_BASENAME} == cc || ${CC_BASENAME} == gcc
COMPILER?=	gcc
STLPORT_PORT?=	devel/stlport
.elif ${CC_BASENAME} == icc
COMPILER?=	icc
STLPORT_PORT?=	devel/stlport-icc
.else
STLPORT_PORT?=	# empty
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000 && ${OSVERSION} < 501103 && !empty(STLPORT_PORT)
RUN_DEPENDS=	${LOCALBASE}/lib/libstlport_${COMPILER}.so:${PORTSDIR}/${STLPORT_PORT}
BUILD_DEPENDS:=	${RUN_DEPENDS}

LDFLAGS+=	-lstlport_${COMPILER}
CPPFLAGS+=	-I${LOCALBASE}/include/stlport
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/zlib

.include <bsd.port.post.mk>
