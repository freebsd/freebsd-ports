# Created by: Xin LI <delphij@FreeBSD.org>
# $FreeBSD$

PORTNAME=	docproj
PORTVERSION=	0.1.20060303
PORTREVISION=	8
CATEGORIES=	chinese
MASTER_SITES=	# none
DISTFILES=	# none
EXTRACT_ONLY=	# none

# Note: Updates from intron@intron.ac should also be
# considered as maintainer updates.

MAINTAINER=	delphij@FreeBSD.org
COMMENT=	Supportive tools for Chinese docproj build

LICENSE=	BSD2CLAUSE

USES=	iconv
USE_TEX=	gbklatex:run

WRKSRC=		${WRKDIR}/src

SRC=		${.CURDIR}/src
MAKE_ARGS+=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} INSTALL_PROGRAM="${INSTALL_PROGRAM}"

PLIST_FILES=	bin/cjktexsty

pre-patch:
	@${CP} -R ${SRC} ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e 's/-liconv/${ICONV_LIB}/' \
		${WRKSRC}/cjktexsty/Makefile

.include <bsd.port.mk>
