# New ports collection makefile for:	ami
# Version required:     ami-0.1.3
# Date created:		05 Jun 1999
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	ami-0.1.3
PKGNAME=	ko-ami-0.1.3
CATEGORIES=	korean x11
MASTER_SITES=	http://www.shinbiro.com/cug/linux/pds0/A/238/ \
		ftp://ftp.kr.freebsd.org/pub/FreeBSD-kr/distfiles/

MAINTAINER=	cjh@kr.freebsd.org

LIB_DEPENDS=    gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

WRKSRC=		${WRKDIR}/ami

ALL_TARGET=	ami

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ami ${PREFIX}/bin/ami

.include <bsd.port.mk>
