# New ports collection makefile for:	smalltalk
# Version required:	1.1.1
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $Id$
#

DISTNAME=	smalltalk-1.1.1
MASTER_SITES=	ftp://prep.ai.mit.edu/pub/gnu/
MAINTAINER=	gpalmer@FreeBSD.ORG

pre-configure:
	@cp ${FILESDIR}/m-fbsd-2.h ${WRKSRC}/config/m-fbsd-2.h
	@(cd ${WRKSRC} ; ./config.mst fbsd-2)
	@${TOUCH} ${TOUCH_FLAGS} ${CONFIGURE_COOKIE}

install:
	@echo ">> The install target for smalltalk-1.1.1 is interactive."
	@echo ">> Please read the file mst.texinfo for more information."
	@${DO_NADA}

.include <bsd.port.mk>
