# New ports collection makefile for:	cxref
# Date created:		23 October 1996
# Whom:			Thomas Gellekum <tg@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	cxref
PORTVERSION=	1.5g
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		http://www.gedanken.demon.co.uk/download-cxref/
MASTER_SITE_SUBDIR=	devel/lang/c
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C program cross-referencing & documentation tool

USE_BISON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		cxref.1 cxref-query.1 cxref-cpp.1 cxref-cpp-configure.1
PLIST_FILES=	bin/cxref bin/cxref-cc bin/cxref-query \
		bin/cxref-cpp bin/cxref-cpp-configure %%DATADIR%%/cxref-cpp.defines
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.mk>
