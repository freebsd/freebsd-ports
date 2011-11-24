# New ports collection Makefile for:	ucommon
# Date created:				21 February 2011
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	ucommon
PORTVERSION=	5.0.7
CATEGORIES=	devel
MASTER_SITES=	GNU
MASTER_SITE_SUBDIR=	commoncpp

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A very light-weight C++ design patternlibrary

USE_GNOME=	pkgconfig gnomehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-D__BSD_VISIBLE
LDFLAGS+=	${PTHREAD_LIBS}

MAN1=	args.1 car.1 commoncpp-config.1 mdsum.1 scrub-files.1 sockaddr.1 \
	ucommon-config.1 zerofill.1

post-patch:
	${REINPLACE_CMD} -e '/HAVE_OPENSSL_FIPS_H/s/define/undef/' \
	   ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
