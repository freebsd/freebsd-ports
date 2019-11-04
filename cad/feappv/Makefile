# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	feappv
PORTVERSION=	4.1i
PORTREVISION=	4
DISTVERSIONPREFIX=v
CATEGORIES=	cad science
MASTER_SITES=	http://projects.ce.berkeley.edu/feap/${PORTNAME}/:1
DISTFILES=	${PORTDOCS}:1
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Finite element analysis program (personal version)

USES=		fortran gmake localbase:ldflags xorg
USE_GITHUB=	yes
GH_ACCOUNT=	sanjayg0
USE_XORG=	x11
MAKEFILE=	makefile
MAKE_ENV=	FEAPPVHOME4_1="${WRKSRC}"
ALL_TARGET=	install

LDFLAGS+=	-lX11 -lm

PLIST_FILES=	bin/feappv lib/libfeappv.a
PORTDOCS=	manual41.pdf

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's| make | $$(MAKE) |' ${WRKSRC}/makefile
	@${REINPLACE_CMD} -e \
		'/^  FF /s|=.*|= ${FC}| ; \
		 /^  CC /s|=.*|= ${CC}| ; \
		 /^  FFOPTFLAG /s|=.*|= ${FFLAGS}| ; \
		 /^  CCOPTFLAG /s|=.*|= ${CFLAGS}| ; \
		 /^  LDOPTIONS /s|=.*|= ${LDFLAGS}| ; \
		 s|Feappv.a|libfeappv.a|' ${WRKSRC}/makefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/feappv ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/libfeappv.a ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${_DISTDIR}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
