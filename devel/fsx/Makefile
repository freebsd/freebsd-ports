PORTNAME=	fsx
DISTVERSION=	0.3.1
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	File System eXerciser
WWW=		https://github.com/asomers/fsx-rs

LICENSE=	APSL-2.0
LICENSE_NAME=	Apple Public Source License 2.0
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cargo

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz \
		share/examples/${PORTNAME}/${PORTNAME}.toml

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.toml ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
