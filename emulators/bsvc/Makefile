# Created by: tenser@spitfire.ecsel.psu.edu
# $FreeBSD$

PORTNAME=	bsvc
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	emulators tk
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/emulators
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extensible hardware simulation framework with MC68K support

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_ENV=	PROJECT_BASE=${STAGEDIR}${PREFIX} WRKSRC=${WRKSRC} WISH=${WISH}

USES+=		tk
MAKE_JOBS_UNSAFE=	yes

pre-patch:
	@${CP} ${WRKSRC}/Makefile.Linux ${WRKSRC}/Makefile

post-patch:

.for cfile in codegen.c listing.c object.c main.c
	@${REINPLACE_CMD} -e 's|exit()|exit(1)|g' ${WRKSRC}/Assemblers/68kasm/${cfile}
.endfor
	@${REINPLACE_CMD} -e 's|^#endif.*$$|#endif|g' \
		${WRKSRC}/Assemblers/68kasm/instlookup.c

	@${FIND} ${WRKSRC} -name "*.[ch]xx" -exec \
		${REINPLACE_CMD} -e \
			's/iostream\.h/iostream/; \
			 s/strstream\.h/strstream/; \
			 s/fstream\.h/fstream/' \{\} \;
	@${FIND} ${WRKSRC} -name Makefile -exec \
		${REINPLACE_CMD} -e 's/make/$(MAKE)/' \{\} \;

.include <bsd.port.mk>
