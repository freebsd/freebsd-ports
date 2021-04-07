PORTNAME=	dsd
PORTVERSION=	1.6.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	comms hamradio

MAINTAINER=	takefu@airport.fm
COMMENT=	Decode several digital voice formats

LICENSE=	ISCL

LIB_DEPENDS=	libmbe.so:comms/mbelib

USE_GITHUB=	yes
GH_ACCOUNT=	szechyjs

USE_LDCONFIG=	yes
PLIST_FILES=	"@(,uucp,4555) bin/dsd"
MAKE_ARGS=	DEST_BASE=${STAGEDIR}${PREFIX}

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -Ee '/ch(grp|mod)/d' -e 's|${PREFIX}|${LOCALBASE}|g;\
		s|install|${INSTALL_PROGRAM}|g;\
		s|gcc|${CC}|g'\
		${WRKSRC}/Makefile
.for i in dsd.h dsd_file.c dsd_mbe.c
	${REINPLACE_CMD} 's|2250|2450|' ${WRKSRC}/${i}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
