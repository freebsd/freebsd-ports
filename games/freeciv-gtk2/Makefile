# New ports collection makefile for:	freeciv
# Version required:	1.7.2
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $Id: Makefile,v 1.16 1999/02/01 01:22:16 obrien Exp $
#

DISTNAME=	freeciv-1.7.2
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.freeciv.org/pub/freeciv/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ada@bsd.org

BUILD_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2
LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

BROKEN='no route to the *single* mastersite'

EXTRACT_CMD=	bzip2
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= | tar xf -

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
