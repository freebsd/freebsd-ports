# ex:ts=8
# New ports collection makefile for:	sircd
# Date created:			Jun 15, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sircd
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.sircd.org/files/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Smart IRC Daemon

USE_OPENSSL=	yes
USE_GMAKE=	yes
CFLAGS+=	"-fPIC"
MAKE_ENV=	LD="${CC}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
ALL_TARGET=	release
INSTALLS_SHLIB=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sircd/sircd ${PREFIX}/sbin/sircd
	${INSTALL_DATA} ${WRKSRC}/sircd/sircd.conf ${PREFIX}/etc/sircd.conf.sample
	${INSTALL_DATA} ${WRKSRC}/syscore/libsyscore.so ${PREFIX}/lib/libsyscore.so
	@${MKDIR} ${PREFIX}/lib/sircd
	${INSTALL_DATA} ${WRKSRC}/sircd/motd.txt ${PREFIX}/lib/sircd/motd.txt
	@${MKDIR} ${PREFIX}/lib/sircd/plugins
	${INSTALL_DATA} ${WRKSRC}/plugins/*.so ${PREFIX}/lib/sircd/plugins

.include <bsd.port.mk>
