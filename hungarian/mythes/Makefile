# New ports collection makefile for:	mythes
# Date created:		2011-07-21
# Whom:			Baptiste Daroussin <bapt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mythes
PORTVERSION=	2003.09.29
CATEGORIES=	hungarian textproc
MASTER_SITES=	http://ftp.osuosl.org/pub/openoffice/contrib/dictionaries/
DISTNAME=	thes_hu_HU

MAINTAINER=	office@FreeBSD.org
COMMENT=	Hungarian thesaurus

LICENSE=	GPLv2

USE_ZIP=	yes
NO_BUILD=	yes

PLIST_FILES=	share/mythes/th_hu_HU.dat \
		share/mythes/th_hu_HU.idx
PLIST_DIRS=	share/mythes

do-install:
	@${MKDIR} ${PREFIX}/share/mythes
	@${INSTALL_DATA} ${WRKDIR}/th_hu_HU.* ${PREFIX}/share/mythes

.include <bsd.port.mk>
