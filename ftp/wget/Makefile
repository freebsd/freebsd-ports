# New ports collection makefile for:	wget
# Version required:	1.5.3
# Date created:		31 December 1996
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.14 1999/06/05 22:31:23 mharo Exp $
#

DISTNAME=	wget-1.5.3
CATEGORIES=	net www
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.dl.ac.uk/ccp14/ftp-mirror/wget/pub/unix/util/wget/ \
		ftp://ftp.informatik.hu-berlin.de/gnu/wget/ \
		ftp://ftp.uni-mainz.de/pub/gnu/wget/ \
		ftp://ftp.max.irk.ru/pub/unix/net/www/wget/
MASTER_SITE_SUBDIR=	wget

MAINTAINER=	obrien@FreeBSD.ORG

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes

INFOFILES=	wget.info

post-install:
.for i in ${INFOFILES}
	install-info ${PREFIX}/info/${i} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
