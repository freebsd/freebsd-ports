# New ports collection makefile for:	xjump
# Date created:				Sun 25 Feb 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	xjump
PORTVERSION=	2.7
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freesoftware.com/pub/linux/debian/${MASTER_SITE_SUBDIR}/ \
		ftp://ftp.jp.debian.org/debian/${MASTER_SITE_SUBDIR}/ \
		ftp://ftp-linux.cc.gatech.edu/pub/linux/distributions/debian/${MASTER_SITE_SUBDIR}/ \
		ftp://ftp.de.debian.org/debian/${MASTER_SITE_SUBDIR}/ \
		ftp://ftp.debian.org/debian/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	dists/stable/main/source/games
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/g}
ALL_TARGET=	xjump

pre-build:
	${PERL} -pi -e "s@gcc -O2@${CC} ${CFLAGS}@g; \
			s@/var/lib/games/xjump@/var/games@g; \
			s@\)/record@\)/xjump.record@g; \
			s@2755@2775@g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} -g games ${WRKSRC}/xjump ${PREFIX}/bin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
