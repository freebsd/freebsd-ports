# ex:ts=8
# Ports collection makefile for:	dbh
# Date created:			Aug 9, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	dbh
PORTVERSION=	1.0.11
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://dbh.sourceforge.net/archive/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:R}-${PORTVERSION:E}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
