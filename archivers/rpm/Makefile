# New ports collection makefile for:	rpm
# Date created:		30 April 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rpm
PORTVERSION=	2.5.6
CATEGORIES=	misc
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-2.5.x/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gdbm.2:${PORTSDIR}/databases/gdbm

USE_GMAKE=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS=	--disable-nls

MAN8=		rpm.8 rpm2cpio.8

pre-configure:
	@(cd ${WRKSRC}/popt && ${AUTOCONF})

.include <bsd.port.mk>
