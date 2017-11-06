# Created by: ijliao
# $FreeBSD$

PORTNAME=	argtable
PORTVERSION=	2.13
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION:S/./-/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ANSI C library for parsing GNU style command line arguments

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g ; \
		 s|^install-data-am: install-dist_exampleDATA|install-data-am: |g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/argtable2.3 ${STAGEDIR}${MAN3PREFIX}/man/man3

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.c ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.h ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.txt ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
