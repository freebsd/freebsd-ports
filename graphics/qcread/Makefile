# New ports collection makefile for:   qcread
# Date created:        23 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	qcread
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.fhttpd.org/pub/qcread/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Supports both color and B&W parallel-port Connectix QuickCam for PC

ONLY_FOR_ARCHS=	i386

USE_GETOPT_LONG=	yes

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I. -DFreeBSD ${CPPFLAGS} \
		-o qcread qcread.c cqc.c -lm ${LDFLAGS}

do-install:
	${INSTALL} ${COPY} -o root -g wheel -m 644 ${WRKSRC}/qcam.conf ${PREFIX}/etc/qcam.conf.dist
	if [ ! -e ${PREFIX}/etc/qcam.conf ]; then \
		${CP} ${PREFIX}/etc/qcam.conf.dist ${PREFIX}/etc/qcam.conf; \
	fi
	${INSTALL_PROGRAM} ${WRKSRC}/qcread ${PREFIX}/bin

.include <bsd.port.mk>
