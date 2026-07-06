PORTNAME=	LMDB_File
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SORTIZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	Perl wrapper around the OpenLDAP's LMDB
WWW=		https://metacpan.org/dist/LMDB_File

LICENSE=	ART20

LIB_DEPENDS=	liblmdb.so:databases/lmdb0

USES=		localbase perl5
USE_PERL5=	configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/LMDB_File/LMDB_File.so

.include <bsd.port.mk>
