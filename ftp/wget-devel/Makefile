# New ports collection makefile for:	wget
# Version required:	1.4.5
# Date created:		31 December 1996
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.3 1997/05/15 07:20:04 tg Exp $
#

DISTNAME=	wget-1.4.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	tg@FreeBSD.ORG

GNU_CONFIGURE=	yes
MAN1=		wget.1

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
		sed -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	-install-info ${PREFIX}/info/wget.info ${PREFIX}/info/dir

.include <bsd.port.mk>
