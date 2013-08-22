# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Tie-LevelDB
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl Interface to the Google LevelDB NoSQL database

LIB_DEPENDS=	leveldb:${PORTSDIR}/databases/leveldb

MAKE_ARGS=	CC=${CXX}
USE_PERL5=	configure
USES=		gmake perl5

MAN3=		Tie::LevelDB.3

post-patch:
	@${REINPLACE_CMD} -e '/build_detect_platform/d' \
		-e 's|build_config.mk|${LOCALBASE}/share/leveldb/&|' \
		-e '/OBJECT/ s|".*\(LevelDB\.o\).*"|"\1"|' \
		-e '/INC/ s|-I|-I${LOCALBASE}/include &|' \
		-e '/LIBS/ s|\[\(.*\)\]|["-L${LOCALBASE}/lib -lleveldb " . (\1)]|' \
			${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
