# New ports collection makefile for:	acpicatools
# Date created:		25 Jun 2001
# Whom:			Mitsuru IWASAKI <iwasaki@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	acpicatools
PORTVERSION=	20021118.0
CATEGORIES=	devel
MASTER_SITES=	http://people.FreeBSD.org/~iwasaki/acpi/ \
		http://developer.intel.com/technology/iapc/acpi/downloads/ \
		${MASTER_SITE_PORTS_JP}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		acpica-unix-20021118.tar.gz
NO_WRKSUBDIR=	yes

MAINTAINER=	iwasaki@FreeBSD.org

pre-install:
		@${MKDIR} ${PREFIX}/man/man8

.include <bsd.port.mk>
