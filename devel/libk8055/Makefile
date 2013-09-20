# Created by: Jake Smith <jake@xz.cx>
# $FreeBSD$

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
USE_CSTD=	gnu89

PLIST_FILES=	bin/k8055 \
		lib/libk8055.c \
		lib/libk8055.o \
		lib/libk8055.so \
		lib/libk8055.so.0.2 \
		include/k8055.h

NO_STAGE=	yes
post-patch:
	@${RM} ${WRKSRC}/libk8055.c.orig

.include <bsd.port.mk>
