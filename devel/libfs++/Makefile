# ex:ts=8
# Ports collection makefile for:	libfs++
# Date created:			Sep 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libfs++
PORTVERSION=	0.1.7
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://bluebat.dnsalias.org/software/libfs++/%SUBDIR%/
MASTER_SITE_SUBDIR=	. archive

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library which provides a file_iterator class

USE_AUTOTOOLS=	libtool:22
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-Wall -g -O2||g'

.include <bsd.port.mk>
