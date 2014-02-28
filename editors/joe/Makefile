# Created by: torstenb@FreeBSD.org
# $FreeBSD$

PORTNAME=	joe
PORTVERSION=	3.7
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES?=	editors
MASTER_SITES=	SF/joe-editor/JOE%20sources/joe-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Joe's Own Editor

LICENSE=	GPLv1

BUILD_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell
RUN_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell

OPTIONS_DEFINE=	DOCS

CONFLICTS=	joe-2.*

USES=		gmake iconv ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${ICONV_LIB}"
CPPFLAGS+=	-I${LOCALBASE}/include

ALL_TARGET=	${PORTNAME}

post-install:
	for rc in jmacsrc joerc jpicorc jstarrc rjoerc; do \
		${MV} ${STAGEDIR}${ETCDIR}/$${rc} ${STAGEDIR}${ETCDIR}/$${rc}.dist ; \
	done

.include <bsd.port.mk>
