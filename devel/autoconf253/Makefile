# New ports collection makefile for:	autoconf
# Version required:     2.12
# Date created:		7 October 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.13 1998/05/04 02:41:51 vanilla Exp $
#

DISTNAME=       autoconf-2.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	torstenb@FreeBSD.ORG

RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${PREFIX}/bin/gm4

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi

.include <bsd.port.mk>
