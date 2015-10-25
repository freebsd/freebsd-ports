# Created by: Bill Fumerola <billf@chc-chimes.com>
# $FreeBSD$

PORTNAME=	qcread
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.fhttpd.org/pub/qcread/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Supports both color and B&W parallel-port Connectix QuickCam for PC

LICENSE=	MIT

BROKEN=		No public distfiles
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

USE_CSTD=	gnu89

ONLY_FOR_ARCHS=	amd64 i386

do-build:
	(cd ${WRKSRC} && ${CC} ${CFLAGS} -I. -DFreeBSD ${CPPFLAGS} \
		-o qcread qcread.c cqc.c -lm ${LDFLAGS})
	@${LN} -sf qcam.conf ${WRKSRC}/qcam.conf.dist

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} qcread \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_DATA} qcam.conf.dist \
		${STAGEDIR}${PREFIX}/etc)

.include <bsd.port.mk>
