# New ports collection makefile for:    Neverwinter Nights Data
# Date created:				4 April 2003
# Whom:					Erik Olson <erikolson@olsonexpress.com>
#
# $FreeBSD$
#

PORTNAME=	linux_nwndata
PORTVERSION=	1.29
CATEGORIES=	games linux
MASTER_SITES=	# ftp://jeuxlinux.com/bioware/Neverwinter_Nights/
DISTNAME=	nwresources${PORTVERSION:S/.//}
EXTRACT_ONLY=	# Don't extract anything

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Neverwinter Nights Data Files

ONLY_FOR_ARCHS=	i386
USE_LINUX_PREFIX=	yes
NO_BUILD=		yes
STRIP=

GAMEDIR=	${PREFIX}/usr/games/
PLIST_SUB+=	NWNDIR="/usr/games/nwn/"
DISTDIRS=	ambient data dmvault hak localvault docs \
		modules music nwm override portraits saves \
		servervault texturepacks \
		chitin.key patch.key dialog.tlk nwnplayer.ini nwncdkey.ini

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		You need to download the data files manually. They are big++: 1.2 gigabyte. You can find them at ftp://jeuxlinux.com/bioware/Neverwinter_Nights/ as ${DISTFILES}. Copy them to ${DISTDIR} and run "make" again there.
.endif

.include <bsd.port.pre.mk>

# Do nothing for the build.  Don't set NO_BUILD because of the earlier
# BUILD_DEPENDS
do-build:

do-install:
	cd ${GAMEDIR}; tar xvfz ${DISTDIR}/${DISTNAME}.tar.gz

.include <bsd.port.post.mk>
