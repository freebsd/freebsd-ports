# New ports collection makefile for:   cheap-call
# Date created:         9 Jun 1999
# Whom:                 Peter Cornelius <pcc@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	cheap-call
PORTVERSION=	0.7e
CATEGORIES=	german
MASTER_SITES=	http://212.227.69.105/download/
DISTNAME=	cheap-call-${LONGVER}.tcl
EXTRACT_SUFX=	.bz2

MAINTAINER=	pcc@gmx.net

RUN_DEPENDS=	wishx:${PORTSDIR}/lang/tclX80

LONGVER=	0.7e-1.9.99

EXTRACT_AFTER_ARGS= | ${CAT} - > ${WRKDIR}/cheap-call-${LONGVER}.tcl
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
STRIP=
USE_BZIP2=	yes
PLIST_SUB=	LONGVER="${LONGVER}"

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/cheap-call-${LONGVER}.tcl ${PREFIX}/bin
	@${LN} -sf ${PREFIX}/bin/cheap-call-${LONGVER}.tcl ${PREFIX}/bin/cheap-call
	@${LN} -sf ${PREFIX}/bin/cheap-call-${LONGVER}.tcl ${PREFIX}/bin/cheapcall

.include <bsd.port.mk>
