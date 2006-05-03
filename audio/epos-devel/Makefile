# New ports collection makefile for:    epos-devel
# Date created:         3 September 2005
# Whom:                 martin@matuska.org
#
# $FreeBSD$
#

PORTNAME=	epos
PORTVERSION=	2.5.36
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	epos

MAINTAINER=	martin@matuska.org
COMMENT=	Text-to-Speech system

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	${REINPLACE_CMD} -e 's/^\(SUBDIRS =.*\)doc/\1/' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
