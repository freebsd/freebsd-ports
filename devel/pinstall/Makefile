# New ports collection makefile for:		pinstall
# Date created:					October 20th 2000
# Whom:						des
#
# $FreeBSD$
#
# This port is self contained in the src directory.
#

PORTNAME=	pinstall
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	des@FreeBSD.org
COMMENT=	A tool for installing files according to a packing list

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/pinstall
USE_PERL5=	yes

SRC=		${.CURDIR}/src

do-fetch:
	@${DO_NADA}

do-install:
	@${INSTALL_SCRIPT} ${SRC}/pinstall.pl ${PREFIX}/bin/pinstall

.include <bsd.port.mk>
