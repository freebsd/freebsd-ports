PORTNAME=	concordance
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Command-line Logitech Harmony configuration tool

LICENSE=	GPLv2

DEPRECATED=	Logitech Harmony were officially discontinued in 2021, last major product in 2019.
EXPIRATION_DATE=2024-12-31

LIB_DEPENDS=	libconcord.so:comms/libconcord

USES=		tar:bzip2
WRKSRC_SUBDIR=	${PORTNAME}
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/concordance \
		share/man/man1/concordance.1.gz

.include <bsd.port.mk>
