PORTNAME=	pjdfstest
DISTVERSION=	0.2.2
CATEGORIES=	filesystems
MASTER_SITES=	CRATESIO
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	asomers@FreeBSD.org
COMMENT=	Generic POSIX file system test suite
WWW=		https://github.com/saidsay-so/pjdfstest

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cargo

# Enabling LTO also sets panic=abort, which breaks pjdfstest.  pjdfstest relies
# on generating panics and then unwinding them.
LTO_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/examples/${PORTNAME}/${PORTNAME}.toml

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.toml ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
