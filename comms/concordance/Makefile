# Created by: Stephen Hurd <shurd@FreeBSD.org>

PORTNAME=	concordance
PORTVERSION=	1.5
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line Logitech Harmony configuration tool

LICENSE=	GPLv2

LIB_DEPENDS=	libconcord.so:comms/libconcord

USES=		tar:bzip2
WRKSRC_SUBDIR=	${PORTNAME}
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/concordance \
		man/man1/concordance.1.gz

.include <bsd.port.mk>
