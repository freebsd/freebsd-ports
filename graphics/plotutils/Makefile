# New ports collection makefile for:	xfig
# Version required:	2.1.1
# Date created:		19 June 1998
# Whom:			Chuck Robey (chuckr)
#
# $Id: Makefile,v 1.2 1998/06/26 04:53:29 asami Exp $
#

DISTNAME=	plotutils-2.1.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	chuckr@FreeBSD.ORG

GNU_CONFIGURE=	yes

.ifdef HAVE_MOTIF
CONFIGURE_ARGS=	--with-motif
.endif

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
