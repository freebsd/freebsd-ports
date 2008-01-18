# New ports collection makefile for:	urjtag
# Date created:		2008-01-05
# Whom:			Bruce M. Simpson
#
# $FreeBSD$
#

PORTNAME=	urjtag
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=urjtag

MAINTAINER=	bms@FreeBSD.org
COMMENT=	Extended utility to work with JTAG-aware boards

BUILD_DEPENDS=	${OPENWINCE_INCLUDE_DEP}:${PORTSDIR}/devel/openwince-include
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+= --without-libusb --without-libftdi --without-ftd2xx \
		 --disable-nls
CONFIGURE_ENV+=	CFLAGS=--std=c99

OPENWINCE_INCLUDE=${LOCALBASE}/include/openwince
OPENWINCE_INCLUDE_DEP=${OPENWINCE_INCLUDE}/common.h

MAN1=		jtag.1 bsdl2jtag.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.5)
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif

post-extract:
	@${REINPLACE_CMD} -E -e \
		"s,/usr/local/include/openwince,${OPENWINCE_INCLUDE}," \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
