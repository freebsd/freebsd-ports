# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	fmars
PORTVERSION=	0.0.207
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://corewar.co.uk/janeczek/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast Memory Array Redcode Simulator

LICENSE=	GPLv2

BUILD_DEPENDS=	guile:lang/guile

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
# Program.
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} x${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME})

# Data.
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for d in rc rc-test
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR})
.endfor

# Documentation (optional).
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
