# ports collection makefile for:   qkmj
# Date created:        21 Jan 2001
# Whom:                clive
#
# $FreeBSD$
#

PORTNAME=	qkmj
PORTVERSION=	95p5
CATEGORIES=	games chinese
MASTER_SITES=	ftp://ftp.csie.nctu.edu.tw/pub/CSIE/qkmj/
MASTER_SITE_SUBDIR=	${PORTNAME}${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}-freebsd
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	clive@FreeBSD.org
COMMENT=	QKMJ - QK Ma2Jong4 client

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS=	c.4:${PORTSDIR}/misc/compat4x
.endif

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_CDROM=	'Do not sell for profit.'

do-install:
	${INSTALL} -c ${DISTDIR}/${DISTNAME} ${PREFIX}/libexec/${DISTNAME}
	@${ECHO} '#!/bin/sh' > ${PREFIX}/bin/${PORTNAME}
	@${ECHO} env TERM=vt100 ${PREFIX}/libexec/${DISTNAME} >> ${PREFIX}/bin/${PORTNAME}
	@${CHMOD} +x ${PREFIX}/bin/${PORTNAME}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
