PORTNAME=	readline
PORTVERSION=	8.2.${PATCHLEVEL}
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	readline-${PORTVERSION:R}

PATCH_SITES=	GNU/readline/readline-${PORTVERSION:R}-patches

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for editing command lines as they are typed
WWW=		https://tiswww.case.edu/php/chet/readline/rltop.html

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

INFO=		history readline rluserman
PLIST_SUB=	PORTVERSION=${PORTVERSION:R}
PORTDOCS=	CHANGES INSTALL README

CPE_VENDOR=	gnu
CPE_VERSION=	${PORTVERSION:R}

# https://ftp.gnu.org/gnu/readline/readline-8.2-patches/
PATCHES=	1 2 3 4 5 6 7 8 9 10 11 12 13
.if defined(PATCHES)
CPE_UPDATE=	${PATCHLEVEL}
PATCHLEVEL=	${PATCHES:On:[-1]}
.for patch in ${PATCHES}
PATCHFILES+=	readline${PORTVERSION:R:S|.||}-${patch:S|^|00|:C|.*(...)$|\1|}
.endfor
.else
PATCHLEVEL=	0
.endif

OPTIONS_DEFINE=	BRACKETEDPASTE DOCS
OPTIONS_DEFAULT=BRACKETEDPASTE
BRACKETEDPASTE_DESC=	Enable bracketed paste

BRACKETEDPASTE_CONFIGURE_ENABLE=	bracketed-paste-default

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/rlconf.h ${WRKSRC}/doc/readline.3 ${WRKSRC}/doc/readline.info ${WRKSRC}/doc/rluserman.info
.if exists(/usr/lib/libtermcapw.so)
	@${REINPLACE_CMD} 's|-ltermcap|-ltermcapw|g' ${WRKSRC}/configure
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libhistory.so ${STAGEDIR}${PREFIX}/lib/libreadline.so

.include <bsd.port.mk>
