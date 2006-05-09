# New ports collection makefile for:	acpicatools
# Date created:		25 Jun 2001
# Whom:			Mitsuru IWASAKI <iwasaki@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	acpicatools
PORTVERSION=	20030523.0
CATEGORIES=	devel
MASTER_SITES=	http://people.FreeBSD.org/~iwasaki/acpi/:g1 \
		http://ftp.ale.org/pub/mirrors/freebsd/distfiles/:g2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:g1,g2 \
		acpica-unix-20030523.tar.gz:g2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Some utilities for Intel ACPICA (Debugger, ASL Compiler and etc.)

NO_WRKSUBDIR=	yes

MAN8=		acpidump.8

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN=		Does not compile on ia64 or amd64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
		${WRKDIR}/Makefile*

.include <bsd.port.post.mk>
