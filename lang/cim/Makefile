# New ports collection makefile for:   cim
# Version required:		2.10
# Date created:			21 Sept 1996
# Whom:				giffunip
#
# $Id: Makefile,v 1.5 1998/02/20 18:39:51 steve Exp $
#

DISTNAME=	cim-2.10
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ifi.uio.no/pub/cim/  \
		ftp://ftp.fenk.wau.nl/pub/lang/simula/compilers/cim/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	devel/lang/simula

MAINTAINER=	ports@FreeBSD.ORG

GNU_CONFIGURE= 	yes
MAN1=		cim.1

pre-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi

.include <bsd.port.mk>
