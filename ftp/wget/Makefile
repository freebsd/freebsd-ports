# New ports collection makefile for:	wget
# Version required:	1.5.0
# Date created:		31 December 1996
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.4 1997/05/22 07:53:29 tg Exp $
#

DISTNAME=	wget-1.5.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	ports@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
		sed -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	-install-info ${PREFIX}/info/wget.info ${PREFIX}/info/dir
	@strip ${PREFIX}/bin/wget

.include <bsd.port.mk>
