# New ports collection makefile for:    Neverwinter Nights Data
# Date created:				4 April 2003
# Whom:					Erik Olson <erikolson@olsonexpress.com>
#
# $FreeBSD$
#

PORTNAME=	linux_nwndata
PORTVERSION=	1.29
PORTREVISION=	1
CATEGORIES=	games linux
MASTER_SITES=	ftp://jeuxlinux.com/bioware/Neverwinter_Nights/
DISTNAME=	nwresources${PORTVERSION:S/.//}
EXTRACT_ONLY=	# Don't extract anything

MAINTAINER=	des@FreeBSD.org
COMMENT=	Neverwinter Nights Data Files

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
NO_BUILD=		yes

GAMEDIR=	${PREFIX}/usr/games/
PLIST_SUB+=	NWNDIR="usr/games/nwn"

do-install:
	(cd ${GAMEDIR} && ${TAR} zxf ${DISTDIR}/${DISTFILES})
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${GAMEDIR}/nwn

.include <bsd.port.mk>
