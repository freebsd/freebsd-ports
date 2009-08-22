# New ports collection makefile for:	libmng
# Date created:		Nov 2, 2000
# Whom:			Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	libmng
PORTVERSION=	1.0.10
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION} \
		http://www.libmng.com/download/


MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Multiple-image Network Graphics (MNG) reference library

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		lcms:${PORTSDIR}/graphics/lcms

OPTIONS=	MNG_OPTIMIZE "Use vendor's new optimization flags" no

REINPLACE_ARGS=	-i ""
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ARGS+=	-j2 WITH_MNG_OPTIMIZE=${WITH_MNG_OPTIMIZE}

USE_LDCONFIG=	yes

MAN3=		libmng.3
MAN5=		mng.5 jng.5

post-extract:
	#
	# Getting rid of the DOS-style end-of-lines left by the vendor
	#
	${FIND} ${WRKSRC} -type f | ${XARGS} ${FILE} |	\
	    ${AWK} -F: '/CRLF/ { print $$1 }' |	\
	    ${XARGS} ${REINPLACE_CMD} -Ee 's,[[:space:]]+$$,,'

post-install:
	cd ${WRKSRC}/doc/man && ${INSTALL_MAN} ${MAN3} ${PREFIX}/man/man3 \
		&& ${INSTALL_MAN} ${MAN5} ${PREFIX}/man/man5

.include <bsd.port.mk>
