# Created by: torstenb@FreeBSD.org
# $FreeBSD$

PORTNAME=	joe
PORTVERSION=	4.5
PORTEPOCH=	1
CATEGORIES?=	editors
MASTER_SITES=	SF/joe-editor/JOE%20sources/joe-${PORTVERSION}

MAINTAINER=	juergen.gotteswinter@googlemail.com
COMMENT=	Joe's Own Editor

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	joe-2.*

USES=		gmake iconv localbase ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SPELL=aspell
LIBS+=		${ICONV_LIB}

ALL_TARGET=	${PORTNAME}

OPTIONS_DEFINE=	ASPELL DOCS

ASPELL_RUN_DEPENDS=	aspell:textproc/aspell

post-patch:
	${REINPLACE_CMD} -e 's|docs/README.old docs/man.md ||' ${WRKSRC}/Makefile.in

post-install:
.for rc in ftyperc jmacsrc joerc jpicorc jstarrc rjoerc
	${MV} ${STAGEDIR}${ETCDIR}/${rc} ${STAGEDIR}${ETCDIR}/${rc}.sample
.endfor

.include <bsd.port.mk>
