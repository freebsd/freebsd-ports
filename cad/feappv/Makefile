# New ports collection makefile for:	FEAPpv
# Date created:		29 Feb 2006
# Whom:			Pedro F. Giffuni
#
# $FreeBSD$
#

PORTNAME=	feappv
PORTVERSION=	2.2
CATEGORIES=	cad science
MASTER_SITES=	http://www.ce.berkeley.edu/projects/feap/feappv/
MASTER_SITE_SUBDIR=	feap
DISTFILES=	${PORTNAME}${PORTVERSION:S/.//}${EXTRACT_SUFX}
.if !defined(NOPORTDOCS)
DISTFILES+=	manual.pdf
.endif
DIST_SUBDIR=	feap
EXTRACT_ONLY=	${PORTNAME}${PORTVERSION:S/.//}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finite Element Analysis Program "personal version"

WRKSRC=		${WRKDIR}/ver${PORTVERSION:S/.//}

USE_ZIP=	yes
USE_XORG=	x11
USE_FORTRAN=	yes
USE_GMAKE=	yes
MAKEFILE=	makefile
MAKE_ARGS=	FF="${FC}" CC="${CC}" FFOPTFLAG="${FFLAGS}" \
		CCOPTFLAG="${CFLAGS} -I{LOCALBASE}/include" \
		LDOPTIONS="-L${LOCALBASE}/lib -lX11 -lm" \
		FINCLUDE="${WRKSRC}/include" ARFEAP="${WRKSRC}/libfeappv.a"
ALL_TARGET=	install
MAKE_JOBS_SAFE=	yes

PORTDOCS=	*
PLIST_FILES=	bin/feappv lib/libfeappv.a

post-patch:
	@${REINPLACE_CMD} -e 's| make | $$(MAKE) |g' ${WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/feappv ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libfeappv.a ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/manual.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
