# New ports collection makefile for:   qcread
# Date created:        23 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	qcread
PORTVERSION=	0.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://mars.illtel.denver.co.us/pub/qcread/ \
		http://mars.illtel.denver.co.us/pub/qcread/

MAINTAINER=	billf@FreeBSD.org

ONLY_FOR_ARCHS=	i386

post-extract:

	@${CP} -r ${WRKSRC}/gnu-getopt/. ${WRKSRC}

do-install:

	${INSTALL} ${COPY} -o root -g wheel -m 644 ${WRKSRC}/qcam.conf ${PREFIX}/etc
	${INSTALL_PROGRAM} ${WRKSRC}/qcread ${PREFIX}/bin

.include <bsd.port.mk>
