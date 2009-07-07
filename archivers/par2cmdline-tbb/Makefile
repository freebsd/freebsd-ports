# New ports collection makefile for:    par2cmdline-tbb
# Whom:                                 Ganael Laplanche <ganael.laplanche@martymac.com>
# Date created:                         27 December 2007
#
# $FreeBSD$
#

PORTNAME=	par2cmdline-tbb
PORTVERSION=	20080420
CATEGORIES=	archivers
MASTER_SITES=	http://chuchusoft.com/par2_tbb/
DISTNAME=	par2cmdline-0.4-tbb-${PORTVERSION}

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Tools for using Parity v2 Archive files (tbb version)

BUILD_DEPENDS=	${LOCALBASE}/lib/libtbb.so:${PORTSDIR}/devel/tbb \
		${NONEXISTENT}:${PORTSDIR}/devel/tbb:extract

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

PORTDOCS=	README
CONFLICTS=	par2cmdline-[0-9]*
PLIST_FILES=	bin/par2 bin/par2create bin/par2repair bin/par2verify

TBBWRKSRC=	`(cd ${PORTSDIR}/devel/tbb && ${MAKE} -V WRKSRC)`

post-configure:
	@${CP} ${TBBWRKSRC}/src/tbb/tbb_misc.h ${WRKSRC}/tbb_misc.h
	@${REINPLACE_CMD} -e 's|#include "tbb/tbb_misc\.h"|#include "tbb_misc.h"|' ${WRKSRC}/par2cmdline.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
