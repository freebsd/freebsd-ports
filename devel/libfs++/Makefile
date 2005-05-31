# ex:ts=8
# Ports collection makefile for:	libfs++
# Date created:			Sep 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libfs++
PORTVERSION=	0.1.7
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://bluebat.dnsalias.org/software/libfs++/%SUBDIR%/
MASTER_SITE_SUBDIR=	. archive

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ library which provides a file_iterator class

USE_REINPLACE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-Wall -g -O2||g'

.include <bsd.port.mk>
