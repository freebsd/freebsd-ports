# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	styx
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.speculate.de/styx/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scanner/parser generator

OPTIONS_DEFINE=	EXAMPLES DOCS
USE_AUTOTOOLS=	libtool
USES=		gmake iconv
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/${PORTNAME}
USE_LDCONFIG=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${TAR} -C ${WRKSRC}/doc \
		--exclude "*.in" --exclude "*Makefile*" -cf - . | \
			${TAR} -C ${STAGEDIR}${DOCSDIR} --unlink -xf -
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${TAR} -C ${WRKSRC} \
		--exclude "*.in" --exclude "*Makefile*" -cf - spe pat | \
			${TAR} -C ${STAGEDIR}${EXAMPLESDIR} --unlink -xf -

.include <bsd.port.mk>
