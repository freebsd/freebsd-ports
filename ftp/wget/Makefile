# New ports collection makefile for:	wget
# Version required:	1.5.3
# Date created:		31 December 1996
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.8 1998/06/28 03:42:10 mph Exp $
#

DISTNAME=	wget-1.5.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	ports@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
		sed -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	-install-info ${PREFIX}/info/wget.info ${PREFIX}/info/dir

.include <bsd.port.mk>
