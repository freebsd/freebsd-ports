# New ports collection makefile for:	libmng
# Date created:		Nov 2, 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	libmng
PORTVERSION=    0.9.3
CATEGORIES=     graphics
MASTER_SITES=   http://www.3-t.com/libmng/download/ \
		${MASTER_SITE_SOURCEFORGE} \
		http://www.libmng.com/download/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=     mi@aldan.algebra.com

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms

INSTALLS_SHLIB=	yes
SHLIB_VER=	0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-jpeg=${LOCALBASE} --with-lcms=${LOCALBASE}
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_SUB=	SHLIB_VER="${SHLIB_VER}"

MAN3=           libmng.3
MAN5=           mng.5 jng.5

post-install:
	cd ${WRKSRC}/doc/man && ${INSTALL_MAN} ${MAN3} ${PREFIX}/man/man3 \
		&& ${INSTALL_MAN} ${MAN5} ${PREFIX}/man/man5

.include <bsd.port.mk>
