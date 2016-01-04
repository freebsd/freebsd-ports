# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	feappv
PORTVERSION=	3.1
PORTREVISION=	5
CATEGORIES=	cad science
MASTER_SITES=	http://www.ce.berkeley.edu/projects/feap/feappv/
DISTFILES=	${PORTNAME}${PORTVERSION:S/.//}${EXTRACT_SUFX} ${PORTDOCS}
DIST_SUBDIR=	${PORTNAME}${PORTVERSION:S/.//}
EXTRACT_ONLY=	${PORTNAME}${PORTVERSION:S/.//}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finite element analysis program (personal version)

USES=		fortran gmake localbase zip
USE_XORG=	x11
MAKEFILE=	makefile
MAKE_ENV=	FEAPPVHOME3_1="${WRKSRC}"
ALL_TARGET=	install

WRKSRC=		${WRKDIR}/ver${PORTVERSION:S/.//}

LDFLAGS+=	-lX11 -lm

PLIST_FILES=	bin/feappv lib/libfeappv.a
PORTDOCS=	manual.pdf

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's| make | $$(MAKE) |' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		'/^FF /s|=.*|= ${FC}| ; \
		 /^CC /s|=.*|= ${CC}| ; \
		 /^FFOPTFLAG /s|=.*|= ${FFLAGS}| ; \
		 /^CCOPTFLAG /s|=.*|= ${CFLAGS}| ; \
		 /^LDOPTIONS /s|=.*|= ${LDFLAGS}| ; \
		 s|Feappv.a|libfeappv.a|' ${WRKSRC}/makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/feappv ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libfeappv.a ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
