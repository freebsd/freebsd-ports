# New ports collection makefile for:	gcal
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=		gcal
PORTVERSION=		3.01
PORTREVISION=	7
CATEGORIES=		deskutils
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GNU Gregorian calendar program

# Global variables
#

USE_GETTEXT=	yes
# required to rebuild info files if needed.
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

INFO=		gcal
MAN1=		gcal.1 gcal2txt.1 tcal.1 txt2gcal.1

# Post-extract
#

# it's not so simple to get rid of splitted *.info-* files
# w/ hacking doc/Makefile.in. so, do nothing and left them.
# post-extract:
# 	@${RM} -f ${WRKSRC}/doc/*/${PORTNAME}.info*

.include <bsd.port.mk>
