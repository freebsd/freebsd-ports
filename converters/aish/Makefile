PORTNAME=	aish
PORTVERSION=	1.13
CATEGORIES=	converters
MASTER_SITES=	http://hp.vector.co.jp/authors/VA004474/etc/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//}u

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ish/uuencode/Base64 converter

MAKE_ARGS=	DSTDIR=${STAGEDIR}${PREFIX}/bin

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/ja/aish
	${INSTALL_DATA} ${WRKSRC}/aish.txt ${STAGEDIR}${PREFIX}/share/doc/ja/aish

.include <bsd.port.mk>
