# New ports collection makefile for:	usogres
# Date Created:				20 Aug, 2003
# Whom:					Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	usogres
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://usogres.good-day.net/download/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Real-time backup utility for PostgreSQL

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

# To avoid syslogd load, add this parameter.
#MAKE_ARGS=	NDEBUG=yes

post-patch:
	cd ${WRKSRC}; ${CP} usogresrc usogresrc.sample

post-install:
	[ -f ${PREFIX}/etc/usogresrc ] || \
		${INSTALL_DATA} ${WRKSRC}/usogresrc ${PREFIX}/etc

.include <bsd.port.mk>
