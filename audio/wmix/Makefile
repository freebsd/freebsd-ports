# New ports collection makefile for:   wmix
# Date created:		2 April 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	wmix
PORTVERSION=	2.2
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.ne.jp/asahi/linux/timecop/
DISTNAME=	${PORTNAME}-${PORTVERSION}-oss

MAINTAINER=	kkonstan@daemon.gr

USE_XPM=	YES
USE_X_PREFIX=	YES

pre-configure:
	${PERL} -pi -e "s@cc@${CC}@g" ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmix ${PREFIX}/bin

.include <bsd.port.mk>
