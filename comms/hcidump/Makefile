# New ports collection makefile for:	hcidump
# Date created:				10 Dec 2004
# Whom:					Pav Lucistnik <pav@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hcidump
PORTVERSION=	1.5.1
CATEGORIES=	comms sysutils
MASTER_SITES=	http://www.geocities.com/m_evmenkin/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Bluetooth traffic dumper, similar to tcpdump

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		hcidump.1
MANCOMPRESSED=	yes
PLIST_FILES=	bin/hcidump

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 502000
IGNORE=		it needs Bluetooth stack (FreeBSD 5.2 or newer)
.endif

.if ${OSVERSION} < 502121
# libbluetooth is only installed on i386 before this version
ONLY_FOR_ARCHS=	i386
.endif

.include <bsd.port.post.mk>
