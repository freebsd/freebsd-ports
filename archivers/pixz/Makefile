PORTNAME=	pixz
DISTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	https://github.com/vasi/${PORTNAME}/releases/download/v${DISTVERSION}/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Parallel, indexing version of XZ
WWW=		https://github.com/vasi/pixz

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		libarchive pkgconfig tar:xz

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/${PORTNAME} share/man/man1/pixz.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/src/pixz.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
