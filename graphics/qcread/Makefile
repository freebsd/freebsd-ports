# New ports collection makefile for:   qcread
# Version required:    0.3
# Date created:        23 August 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.1.1.1 1998/11/16 20:38:21 billf Exp $
#

DISTNAME=	qcread-0.3
CATEGORIES=	graphics
MASTER_SITES=	ftp://phobos.illtel.denver.co.us/pub/qcread/ \
		http://phobos.illtel.denver.co.us/pub/qcread/

MAINTAINER=	billf@FreeBSD.ORG

ONLY_FOR_ARCHS=	i386

post-extract:

	${CP} -r ${WRKSRC}/gnu-getopt/. ${WRKSRC}

do-install:

	${INSTALL} ${COPY} -o root -g wheel -m 644 ${WRKSRC}/qcam.conf ${PREFIX}/etc
	${INSTALL_PROGRAM} ${WRKSRC}/qcread ${PREFIX}/bin

.include <bsd.port.mk>
