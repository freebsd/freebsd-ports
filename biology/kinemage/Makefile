# New ports collection Makefile for: kinemage
# Date created:         Dec 4 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

PORTNAME=	kinemage
PORTVERSION=	5.79
CATEGORIES=	biology
# There is no distfile to fetch here, just a dir of badly formatted sources
#MASTER_SITES=	ftp://kinemage.biochem.duke.edu/OPEN_SOURCE/
#MASTER_SITE_SUBDIR=	MAGE_001120
# I've repackaged their sources for now and Will Andrews <will@freebsd.org>
# is hosting
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	will
DISTNAME=	mage-001120

MAINTAINER=	jeremy@external.org
COMMENT=	A molecular visualization program with special functions

USE_MOTIF=	YES

ALL_TARGET=	mage
PLIST_FILES=	bin/kinemage

# When the time comes to use the actual master site, this snippet
# will replace the carriage returns with newlines
# perl -i -pe 's/\r/\n/g' ${WRKSRC}/*

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mage ${PREFIX}/bin/kinemage

.include <bsd.port.mk>
