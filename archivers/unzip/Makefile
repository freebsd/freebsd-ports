DISTFILES=	unzip512.tar.Z
DISTNAME=	unzip-5.12
MASTER_SITES=	ftp://garbo.uwasa.fi/unix/arcers/
CATEGORIES+=	archivers
MAKEFILE=       unix/Makefile
ALL_TARGET=     bsd
MAKE_FLAGS=     LOCAL_UNZIP="-O2 -DCHECK_EOF" \
		INSTALL="install -c -o bin -g bin" \
		prefix=${PREFIX} -f

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
