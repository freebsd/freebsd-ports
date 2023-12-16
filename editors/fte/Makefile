PORTNAME=	fte
PORTVERSION=	20110708
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX} \
		${DISTNAME}-common${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full-featured text editor for X11
WWW=		https://fte.sourceforge.net/

LICENSE=	ART10 GPLv2
LICENSE_COMB=	dual

DEPRECATED=	Upstream last release was in 2001
EXPIRATION_DATE=	2024-01-16

USES=		perl5 zip xorg
USE_PERL5=	build
USE_XORG=	x11 xpm

MAKE_ENV=	INSTALL_NONROOT=1

CFLAGS+=	-DHAVE_STRLCAT -DHAVE_STRLCPY

WRKSRC=		${WRKDIR}/fte

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|^PREFIX=|PREFIX?=|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e \
		's|\([[:space:]]\)\($$BINDIR\)|\1$$DESTDIR\2|g ; \
		 s|\([[:space:]]\)\($$LIBDIR\)|\1$$DESTDIR\2|g ; \
		 s|\([[:space:]]\)\($$CONFIGDIR\)|\1$$DESTDIR\2|g ; \
		 s|\([[:space:]]\)\($$LOCALCONFIGDIR\)|\1$$DESTDIR\2|g ; \
		 /fterc/s|^|#|' ${WRKSRC}/install

post-install:
.for i in cfte xfte
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
