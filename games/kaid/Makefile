# Created by: Sebastiaan van Erk
# $FreeBSD$

PORTNAME=		kaid
PORTVERSION=		7.0.0.4b
PORTREVISION=		3
CATEGORIES=		games net
MASTER_SITES=		http://www.teamxlink.co.uk/binary/
MASTER_SITE_SUBDIR=
DISTNAME=		${PORTNAME}_tree_${PORTVERSION}
EXTRACT_SUFX=		.zip

MAINTAINER=		ports@FreeBSD.org
COMMENT=		XLink Kai tunneling server

BROKEN=			Does not fetch
DEPRECATED=		Does not fetch
EXPIRATION_DATE=	2013-08-07

NO_WRKSUBDIR=		yes
USE_GMAKE=		yes
USES=			bison
USE_ZIP=		yes
CC=			gcc
CPP=			g++
MAKE_ARGS=		PREFIX="${PREFIX}" SYSTEM_CFLAGS="${CFLAGS}"

NO_PACKAGE=		contains compile time path info, ignores cc cxx

pre-configure:
	@${GMAKE} -C ${WRKSRC} dist-clean

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/kaid ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/kaid.conf ${PREFIX}/etc/kaid.conf.sample
	${INSTALL_SCRIPT} ${FILESDIR}/kaid.sh ${PREFIX}/etc/rc.d

.include <bsd.port.mk>
