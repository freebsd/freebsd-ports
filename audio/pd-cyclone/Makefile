PORTNAME=	cyclone
DISTVERSION=	0.2~beta3
CATEGORIES=	audio
MASTER_SITES=	DEBIAN/pool/main/p/pd-${PORTNAME}
PKGNAMEPREFIX=	pd-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}_${DISTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Pd library of clones of Max/MSP 4.5 objects
WWW=		http://puredata.info/downloads/cyclone

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	pd:audio/pd
RUN_DEPENDS=	pd:audio/pd

USES=		gmake

WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}miXedSon-0.2beta3

post-patch:
	@${REINPLACE_CMD} -e 's|Linux|FreeBSD|g'   \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|cflags =|cflags = -I${LOCALBASE}/include/pd -fcommon|' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|GNU/kFreeBSD|FreeBSD|g' \
		${WRKSRC}/Makefile.pdlibbuilder
	@${REINPLACE_CMD} -e 's|/usr/include|/usr/local/include|g' \
		${WRKSRC}/Makefile.pdlibbuilder

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/pd-externals/cyclone
	${FIND} ${WRKSRC} -name "*.pd" -exec ${INSTALL_DATA} {} \
		${STAGEDIR}${PREFIX}/lib/pd-externals/cyclone \;
	${FIND} ${WRKSRC} -name "*.pd_linux" -exec ${INSTALL_PROGRAM} {} \
		${STAGEDIR}${PREFIX}/lib/pd-externals/cyclone \;

.include <bsd.port.mk>
