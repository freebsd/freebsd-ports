PORTNAME=	seqwish
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.12
CATEGORIES=	biology
MASTER_SITES=	https://github.com/pangenome/seqwish/releases/download/v${DISTVERSION}/
DISTFILES=	seqwish-v0.7.12.tar.gz

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Alignment to variation graph inducer
WWW=		https://github.com/pangenome/seqwish

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo pkgconfig

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION}

PLIST_FILES=	bin/${PORTNAME}

# tests as of 0.7.12: test result: ok. 1 passed; 0 failed; 0 ignored; 0 measured; 0 filtered out; finished in 0.04s

.include <bsd.port.mk>
