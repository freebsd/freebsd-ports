# New ports collection makefile for:	de-linux-eagle
# Date created:				30 August 2002
# Whom:					Thomas E. Zander <riggs@rrr.de>
#
# $FreeBSD$
#

PKGNAMEPREFIX?=	de-
EAGLELANG?=	ger
CATEGORIES?=	german cad linux

MAINTAINER=	riggs@rrr.de
COMMENT=	An easy to use, yet powerful tool for designing printed circuit boards

CONFLICTS=	linux-eagle-[0-9]*

SLAVE_PORT=	yes
MASTER_PORT=	cad/linux-eagle
FILESDIR=	${.CURDIR}/../../${MASTER_PORT}/files

.include "../../cad/linux-eagle/Makefile"
