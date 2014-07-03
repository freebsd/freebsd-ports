# Created by: ijliao
# $FreeBSD$

PORTNAME=	argtable
PORTVERSION=	2.13
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION:S/./-/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	ANSI C library for parsing GNU style command line arguments

OPTIONS_DEFINE=	DOCS EXAMPLES

USES=		libtool
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/s|doc||g ; \
		 s|^install-data-am: |install-data-am: #|g' ${WRKSRC}/Makefile.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/argtable2.3 ${STAGEDIR}${MAN3PREFIX}/man/man3
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.gif ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.ps ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.c ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.h ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.txt ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
