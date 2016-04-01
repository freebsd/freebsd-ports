# Created by: torstenb@FreeBSD.org
# $FreeBSD$

PORTNAME=	joe
PORTVERSION=	4.2
PORTEPOCH=	1
CATEGORIES?=	editors
MASTER_SITES=	SF/joe-editor/JOE%20sources/joe-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Joe's Own Editor

LICENSE=	GPLv2

BUILD_DEPENDS=	aspell:textproc/aspell
RUN_DEPENDS=	aspell:textproc/aspell

OPTIONS_DEFINE=	DOCS

CONFLICTS=	joe-2.*

USES=		gmake iconv ncurses
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB}

ALL_TARGET=	${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|docs/README.old docs/man.md ||' ${WRKSRC}/Makefile.in

post-install:
	for rc in jmacsrc joerc jpicorc jstarrc rjoerc; do \
		${MV} ${STAGEDIR}${ETCDIR}/$${rc} ${STAGEDIR}${ETCDIR}/$${rc}.sample ; \
	done

.include <bsd.port.mk>
