# New ports collection makefile for:	id3lib
# Date Created:				26 Oct 2000
# Whom:					Roman Shterenzon <roman@xpert.com>
#
# $FreeBSD$
#

PORTNAME=	id3lib
PORTVERSION=	3.8.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roman@xpert.com

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv

USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_SHLIB=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if ${CC} == cc || ${CC} == gcc
COMPILER?=	gcc
.else
COMPILER?=	${CC}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
RUN_DEPENDS=	${LOCALBASE}/lib/libstlport_${COMPILER}.so:${PORTSDIR}/devel/stlport${COMPILER:C/^/-/:S/-gcc//}
BUILD_DEPENDS:=	${RUN_DEPENDS}

LDFLAGS+=	-lstlport_${COMPILER}
CPPFLAGS+=	-I${LOCALBASE}/include/stlport
.endif

post-extract:
	@${RM} -rf ${WRKSRC}/zlib

.include <bsd.port.post.mk>
