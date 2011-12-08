# New ports collection makefile for:	libk8055
# Date created:				9 October 2011
# Whom:					Jake Smith <jake@xz.cx>
#
# $FreeBSD$
#

PORTNAME=	libk8055
PORTVERSION=	0.2
CATEGORIES=	devel
MASTER_SITES=	http://www.horizon9.org/~geroy/download/k8055/ \
		http://xz.cx/downloads/k8055/

MAINTAINER=	jake@xz.cx
COMMENT=	Velleman K8055 USB experimental board support and command line tool

MAN1=		k8055.1
MANCOMPRESSED=	yes
USE_LDCONFIG=	yes

PLIST_FILES=	bin/k8055 \
		lib/libk8055.c \
		lib/libk8055.o \
		lib/libk8055.so \
		lib/libk8055.so.0.2 \
		include/k8055.h

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not compile on FreeBSD 7.X
.endif

post-patch:
	@${RM} ${WRKSRC}/libk8055.c.orig

.include <bsd.port.post.mk>
