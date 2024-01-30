PORTNAME=	fstrcmp
PORTVERSION=	0.7.D001
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/fstrcmp/fstrcmp/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for fuzzy string comparisons
WWW=		https://fstrcmp.sourceforge.net/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake libtool:build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfstrcmp.so

.include <bsd.port.mk>
