# New ports collection makefile for: vcg
# Version required:     1.30.r3.17

DISTNAME=	vcg.1.30
DISTFILES=	vcg.1.30.r3.17.tgz
MASTER_SITES=	ftp://ftp.cs.uni-sb.de/pub/graphics/vcg/
CATEGORIES+=	graphics

pre-patch:
	@mkdir -p ${WRKSRC}/preconf/X11ccFreeBSD
	@cp ${FILESDIR}/conf ${WRKSRC}/preconf/X11ccFreeBSD
	@cp ${FILESDIR}/demo.csh ${WRKSRC}/preconf/X11ccFreeBSD
	@cp ${FILESDIR}/globals.h ${WRKSRC}/preconf/X11ccFreeBSD
	@cp ${FILESDIR}/tMakefile ${WRKSRC}/preconf/X11ccFreeBSD

.include <bsd.port.mk>
