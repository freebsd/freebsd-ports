# New ports collection makefile for:	pathchirp
# Date created:			19 May 2005
# Whom:				dikshie <dikshie@lapi.itb.ac.id>
#
# $FreeBSD$
#

PORTNAME=	pathchirp
PORTVERSION=	2.4.0
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.spin.rice.edu/Software/pathChirp/

MAINTAINER=	dikshie@lapi.itb.ac.id
COMMENT=	A measurement tool for available bandwidth estimation

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PLIST_FILES=	bin/pathchirp_rcv bin/pathchirp_snd bin/pathchirp_run

do-install:
.for f in pathchirp_rcv pathchirp_snd pathchirp_run
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/${ARCH}/${f} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
