# New ports collection makefile for:	autoconf
# Version required:     2.12
# Date created:		7 October 1995
# Whom:			torstenb@FreeBSD.ORG
#
# $Id: Makefile,v 1.10 1997/01/16 10:11:37 torstenb Exp $
#

DISTNAME=       autoconf-2.12
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}

RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

MAINTAINER=	torstenb@FreeBSD.ORG

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${PREFIX}/bin/gm4

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
	  sed -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi
	install-info ${PREFIX}/info/autoconf.info ${PREFIX}/info/dir
	install-info ${PREFIX}/info/standards.info ${PREFIX}/info/dir

.include <bsd.port.mk>
