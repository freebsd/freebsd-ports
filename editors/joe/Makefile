# Created by: torstenb@FreeBSD.org
# $FreeBSD$

PORTNAME=	joe
PORTVERSION=	4.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES?=	editors
MASTER_SITES=	SF/joe-editor/JOE%20sources/joe-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Joe's Own Editor

LICENSE=	GPLv2


OPTIONS_DEFINE=	ASPELL DOCS

CONFLICTS=	joe-2.*

USES=		gmake iconv ncurses
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib ${ICONV_LIB}

ALL_TARGET=	${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASPELL}
RUN_DEPENDS=	aspell:textproc/aspell
.endif

post-patch:
	${REINPLACE_CMD} -e 's|docs/README.old docs/man.md ||' ${WRKSRC}/Makefile.in

post-install:
	for rc in jmacsrc joerc jpicorc jstarrc rjoerc; do \
		${MV} ${STAGEDIR}${ETCDIR}/$${rc} ${STAGEDIR}${ETCDIR}/$${rc}.sample ; \
	done

.include <bsd.port.mk>
