# ex:ts=8
# Ports collection makefile for:  wget
# Version required: 0.0
# Date created:			  31 December 1996
# Whom:				  Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	wget-1.5.3
CATEGORIES=	ftp www
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.dl.ac.uk/ccp14/ftp-mirror/wget/pub/unix/util/wget/ \
		ftp://ftp.informatik.hu-berlin.de/gnu/wget/ \
		ftp://ftp.uni-mainz.de/pub/gnu/wget/ \
		ftp://ftp.max.irk.ru/unix/net/www/wget/
MASTER_SITE_SUBDIR=	wget

MAINTAINER=	obrien@FreeBSD.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CPPFLAGS=-I${PREFIX}/include \
		LDFLAGS=-L${PREFIX}/lib

INFOFILES=	wget.info

post-install:
.for i in ${INFOFILES}
	install-info ${PREFIX}/info/${i} ${PREFIX}/info/dir
.endfor

.include <bsd.port.mk>
