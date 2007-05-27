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

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Broken with gcc 4.2
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|-Wall -g -O2||g'

.include <bsd.port.post.mk>
