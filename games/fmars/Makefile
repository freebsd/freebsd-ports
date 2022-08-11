PORTNAME=	fmars
PORTVERSION=	0.0.207
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://corewar.co.uk/janeczek/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Fast Memory Array Redcode Simulator

LICENSE=	GPLv2

BUILD_DEPENDS=	guile:lang/guile1

USES=		gmake tar:bzip2
ALL_TARGET=	x${PORTNAME}

OPTIONS_DEFINE=		DOCS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	OPTIMIZED_CFLAGS

OPTIMIZED_CFLAGS_CFLAGS=-fomit-frame-pointer

post-patch:
	@${REINPLACE_CMD} -e \
		's|^\(CC\) |#\1 | ; \
		 s|^\(CFLAGS\) |#\1 | ; \
		 s|^\(OPTS\) |#\1 | ; \
		 s|gcc -E|$$(CC) -E|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/x${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} "rc rc-test" ${STAGEDIR}${DATADIR})

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
