PORTNAME=	joe
DISTVERSION=	4.8
PORTEPOCH=	1
CATEGORIES?=	editors
MASTER_SITES=	SF/joe-editor/JOE%20sources/joe-${DISTVERSION}

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Joe's Own Editor
WWW=		https://sourceforge.net/projects/joe-editor/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		desktop-file-utils gmake iconv ncurses
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SPELL=aspell

ALL_TARGET=	${PORTNAME}

CONFLICTS=	jupp

OPTIONS_DEFINE=	ASPELL DOCS

ASPELL_RUN_DEPENDS=	aspell:textproc/aspell

post-patch:
	${REINPLACE_CMD} -e 's|docs/README.old docs/man.md ||' ${WRKSRC}/Makefile.in

post-install:
.for rc in ftyperc jmacsrc joerc jpicorc jstarrc rjoerc
	${MV} ${STAGEDIR}${ETCDIR}/${rc} ${STAGEDIR}${ETCDIR}/${rc}.sample
.endfor

.include <bsd.port.mk>
