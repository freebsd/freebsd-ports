# New ports collection makefile for:	wget
# Version required:	1.5.3
# Date created:		31 December 1996
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.12 1999/03/20 17:18:04 nectar Exp $
#

DISTNAME=	wget-1.5.3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.dl.ac.uk/ccp14/ftp-mirror/wget/pub/unix/util/wget/ \
		ftp://ftp.informatik.hu-berlin.de/gnu/wget/ \
		ftp://ftp.uni-mainz.de/pub/gnu/wget/ \
		ftp://ftp.max.irk.ru/pub/unix/net/www/wget/
MASTER_SITE_SUBDIR=	wget

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes

INFOFILES=	wget.info

post-install:
	if [ ! -f ${PREFIX}/info/dir ]; then \
		${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for i in ${INFOFILES}
	install-info ${PREFIX}/info/${i} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
