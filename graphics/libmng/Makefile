# New ports collection makefile for:	libmng
# Date created:		Nov 2, 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	libmng
PORTVERSION=	1.0.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.libmng.com/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms

USE_REINPLACE=	yes

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	-j2

INSTALLS_SHLIB=	yes

MAN3=		libmng.3
MAN5=		mng.5 jng.5

post-patch:
	test ! -e ${PREFIX}/include/lcms.h || ${REINPLACE_CMD} -e \
		's%lcms/lcms.h%lcms.h%' ${WRKSRC}/libmng_types.h

post-install:
	cd ${WRKSRC}/doc/man && ${INSTALL_MAN} ${MAN3} ${PREFIX}/man/man3 \
		&& ${INSTALL_MAN} ${MAN5} ${PREFIX}/man/man5

.include <bsd.port.mk>
