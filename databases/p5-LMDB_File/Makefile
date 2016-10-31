# Created by: vanilla@
# $FreeBSD$

PORTNAME=	LMDB_File
PORTVERSION=	0.10
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Perl wrapper around the OpenLDAP's LMDB

LICENSE=	ART20

LIB_DEPENDS=	liblmdb.so:databases/lmdb

CFLAGS+=	-I${LOCALBASE}/include
USES=		perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/LMDB_File/LMDB_File.so

.include <bsd.port.mk>
