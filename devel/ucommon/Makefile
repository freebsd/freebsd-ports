# Created by: gahr
# $FreeBSD$

PORTNAME=	ucommon
PORTVERSION=	6.0.3
CATEGORIES=	devel
MASTER_SITES=	http://www.gnutelephony.org/dist/tarballs/ \
    		http://www.da3m0n8t3r.com/gnutelephony/www.gnutelephony.org/dist/tarballs/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Very lightweight C++ design pattern library

LICENSE=	LGPL3

USES=	pathfix
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--bindir=${PREFIX}/bin/${PORTNAME}

MAN1=	args.1 car.1 commoncpp-config.1 mdsum.1 pdetach.1 \
	scrub-files.1 sockaddr.1 ucommon-config.1 zerofill.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000000
post-patch:
	${REINPLACE_CMD} -e '/HAVE_OPENSSL_FIPS_H/s/define/undef/' \
	    ${WRKSRC}/${CONFIGURE_SCRIPT}

.endif

regression-test: build
	cd ${WRKSRC}/test && ${MAKE} check

.include <bsd.port.post.mk>
