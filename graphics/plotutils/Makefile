# New ports collection makefile for:	plotutils
# Version required:	2.1.1
# Date created:		19 June 1998
# Whom:			Chuck Robey (chuckr)
#
# $FreeBSD$
#

DISTNAME=	plotutils-2.1.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	plotutils

MAINTAINER=	chuckr@FreeBSD.org

USE_XLIB=	yes
GNU_CONFIGURE=	yes

.ifdef HAVE_MOTIF
CONFIGURE_ARGS=	--with-motif
# to ensure dependency info is generated properly
REQUIRES_MOTIF=	yes
.endif

post-install:
	${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
