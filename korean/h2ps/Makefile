# New ports collection makefile for:    h2ps-2.06
# Date created:         20 May 1997
# Whom:                 CHOI Junho <junker@jazz.snu.ac.kr>
#
# $FreeBSD$
#
# Thanks to SungGon Yi <skon@stats.snu.ac.kr> for advising 2.06 ports
#

PORTNAME=	h2ps
PORTVERSION=	2.06
CATEGORIES=	korean print
MASTER_SITES=	ftp://cglab.snu.ac.kr/pub/hangul/n3f/tar/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	cjh@FreeBSD.org

pre-build:
	@(cd ${WRKSRC}; make clean)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/h2ps ${PREFIX}/bin

.include <bsd.port.mk>
