# Created by: Stephen Hurd <shurd@sasktel.net>
# $FreeBSD$

PORTNAME=	concordance
PORTVERSION=	1.1
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	shurd@sasktel.net
COMMENT=	Command-line Logitech Harmony configuration tool

LICENSE=	GPLv2

LIB_DEPENDS=	libconcord.so:${PORTSDIR}/comms/libconcord

USES=		tar:bzip2
WRKSRC_SUBDIR=	${PORTNAME}
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/concordance \
		man/man1/concordance.1.gz

.include <bsd.port.mk>
