PORTNAME=	joe
PORTVERSION=	4.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES?=	editors
MASTER_SITES=	SF/joe-editor/JOE%20sources/joe-${PORTVERSION}

MAINTAINER=	juergen.gotteswinter@googlemail.com
COMMENT=	Joe's Own Editor
WWW=		https://sourceforge.net/projects/joe-editor/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	jupp

USES=		gmake iconv localbase ncurses
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
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
