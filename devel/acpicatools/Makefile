# New ports collection makefile for:	acpicatools
# Date created:		25 Jun 2001
# Whom:			Mitsuru IWASAKI <iwasaki@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	acpicatools
PORTVERSION=	20030523.0
CATEGORIES=	devel
MASTER_SITES=	http://people.FreeBSD.org/~iwasaki/acpi/ \
		http://developer.intel.com/technology/iapc/acpi/downloads/ \
		${MASTER_SITE_PORTS_JP}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		acpica-unix-20030523.tar.gz
NO_WRKSUBDIR=	yes

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Some utilities for Intel ACPICA (Debugger, ASL Compiler and etc.).

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN=		"Does not compile on ia64 or amd64"
.endif

pre-install:
		@${MKDIR} ${PREFIX}/man/man8

.include <bsd.port.post.mk>
