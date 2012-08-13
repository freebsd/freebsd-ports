# New ports collection Makefile for:	ucommon
# Date created:				21 February 2011
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	ucommon
PORTVERSION=	5.5.0
CATEGORIES=	devel
MASTER_SITES=	http://www.gnutelephony.org/dist/tarballs/ \
    		http://www.da3m0n8t3r.com/gnutelephony/www.gnutelephony.org/dist/tarballs/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A very lightweight C++ design patternlibrary

LICENSE=	LGPL3

USE_GNOME=	pkgconfig gnomehack
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-D__BSD_VISIBLE
LDFLAGS+=	${PTHREAD_LIBS}
CONFIGURE_ARGS+=--bindir=${PREFIX}/bin/${PORTNAME}

MAN1=	args.1 car.1 commoncpp-config.1 mdsum.1 pdetach.1 \
	scrub-files.1 sockaddr.1 ucommon-config.1 zerofill.1

post-patch:
	${REINPLACE_CMD} -e '/HAVE_OPENSSL_FIPS_H/s/define/undef/' \
	   ${WRKSRC}/${CONFIGURE_SCRIPT}

test:	build
	cd ${WRKSRC}/test && ${MAKE} check
	

.include <bsd.port.mk>
