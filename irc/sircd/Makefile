# ex:ts=8
# New ports collection makefile for:	sircd
# Date created:			Jun 15, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	sircd
PORTVERSION=	0.2.5a
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.sircd.org/files/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/a/-alpha/}

MAINTAINER=	ports@FreeBSD.org

USE_OPENSSL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/server
USE_GMAKE=	yes
ALL_TARGET=	release
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e "s,-lssl,-lssl -lcrypto,g" ${WRKSRC}/sircd/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sircd/sircd ${PREFIX}/sbin
	${INSTALL} ${WRKSRC}/../syscore/libsyscore.so ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/sircd/sircd.conf ${PREFIX}/etc/sircd.conf.sample
	${MKDIR} ${PREFIX}/share/sircd/plugins
.for file in mod_base.so mod_oper.so
	${INSTALL} ${WRKSRC}/plugins/${file} ${PREFIX}/share/sircd/plugins
.endfor
	${INSTALL_DATA} ${WRKSRC}/sircd/motd.txt ${PREFIX}/share/sircd

.include <bsd.port.mk>
