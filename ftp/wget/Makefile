# New ports collection makefile for:	wget
# Version required:	1.5.3
# Date created:		31 December 1996
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.9 1998/10/08 06:55:22 tg Exp $
#

DISTNAME=	wget-1.5.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.dl.ac.uk/ccp14/ftp-mirror/wget/pub/unix/util/wget/ \
		ftp://ftp.informatik.hu-berlin.de/gnu/wget/ \
		ftp://ftp.uni-mainz.de/pub/gnu/wget/ \
		ftp://ftp.max.irk.ru/pub/unix/net/www/wget/

MAINTAINER=	ports@FreeBSD.ORG

GNU_CONFIGURE=	yes

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
		sed -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
	-install-info ${PREFIX}/info/wget.info ${PREFIX}/info/dir

.include <bsd.port.mk>
