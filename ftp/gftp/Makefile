# New ports collection makefile for:	gftp
# Version required:	2.0.1
# Date Created:		21 Feb 1999
# Whom:			Damjan Marion <dmarion@open.hr>
#
# $FreeBSD$
#

DISTNAME=	gftp-2.0.1
CATEGORIES=	ftp
MASTER_SITES=	http://www.newwave.net/~masneyb/

MAINTAINER=	dmarion@open.hr

LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_AUTOCONF=	yes
USE_X_PREFIX=	yes

pre-install:
	find ${WRKSRC} -name \*.orig -exec ${RM} -f \{} \;

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gftp ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/gftp
.for i in sample.gftp/*
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/gftp
.endfor

.include <bsd.port.mk>
