# New ports collection Makefile for:	bsvc
# Date created:		03-Mar-1997
# Whom:			tenser@spitfire.ecsel.psu.edu
#
# $FreeBSD$
#

PORTNAME=	bsvc
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	emulators tk84
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	system/emulators
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extensible hardware simulation framework with MC68K support

WRKSRC=		${WRKDIR}/${DISTNAME}/src
MAKE_ENV=	PROJECT_BASE=${PREFIX} WRKSRC=${WRKSRC}
USE_TK_RUN=	yes

.include <bsd.port.pre.mk>

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

.include <bsd.port.post.mk>
