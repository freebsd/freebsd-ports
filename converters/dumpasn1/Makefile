PORTNAME=	dumpasn1
PORTVERSION=	20210212
CATEGORIES=	converters security
MASTER_SITES=	https://www.cs.auckland.ac.nz/~pgut001/
DISTFILES=	dumpasn1.c dumpasn1.cfg
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	yes

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Dumps the contents of an ASN.1 encoded file, e.g. an SSL certificate

LICENSE=	DUMPASN1
LICENSE_NAME=	dumpasn1 license
LICENSE_TEXT=	You can use this code in whatever way you want, as long as you don't try to claim you wrote it
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/dumpasn1.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && \
	${CC} ${CFLAGS} -DCONFIG_NAME=\"${PREFIX}/share/dumpasn1/dumpasn1.cfg\" -o dumpasn1 dumpasn1.c

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/dumpasn1
	${INSTALL_PROGRAM} ${WRKSRC}/dumpasn1 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/dumpasn1.cfg ${STAGEDIR}${PREFIX}/share/dumpasn1

.include <bsd.port.mk>
