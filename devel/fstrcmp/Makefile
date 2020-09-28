# $FreeBSD$

PORTNAME=	fstrcmp
PORTVERSION=	0.7.D001
CATEGORIES=	devel
MASTER_SITES=	SF/fstrcmp/fstrcmp/${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for fuzzy string comparisons

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake libtool:build
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfstrcmp.so

.include <bsd.port.mk>
