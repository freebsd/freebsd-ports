# ports collection makefile for:   qkmj
# Date created:        21 Jan 2001
# Whom:                clive
#
# $FreeBSD$
#

PORTNAME=	qkmj
PORTVERSION=	95p4
CATEGORIES=	games chinese
MASTER_SITES=	ftp://ftp.csie.nctu.edu.tw/pub/CSIE/qkmj/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}-freebsd
EXTRACT_SUFX=
EXTRACT_ONLY=

MAINTAINER=	clive@FreeBSD.org

NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_CDROM=	'Do not sell for profit.'

do-install:
	${INSTALL} -c ${DISTDIR}/${DISTNAME} ${PREFIX}/bin/${DISTNAME}
	@${LN} -s ${PREFIX}/bin/${DISTNAME} ${PREFIX}/bin/${PORTNAME}
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.mk>
