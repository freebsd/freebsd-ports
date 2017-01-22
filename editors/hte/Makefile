# Created by: Ying-Chieh Liao
# $FreeBSD$

PORTNAME=	hte
PORTVERSION=	2.1.0
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/ht-source
DISTNAME=	ht-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File editor/viewer/analyzer for executables

LICENSE=	GPLv2

USES=		ncurses tar:bzip2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/hte

OPTIONS_DEFINE=		DOCS LZO2 X11
OPTIONS_DEFAULT=	X11

LZO2_DESC=	External lzo2 compression support
X11_DESC=	X11 textmode support

NOT_FOR_ARCHS=	ia64
NOT_FOR_ARCHS_REASON=	does not build on ia64

LZO2_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
LZO2_CONFIGURE_OFF=	--with-included-lzo
X11_USE=		XORG=x11
X11_CPPFLAGS=		-I${LOCALBASE}/include
X11_LDFLAGS=		-L${LOCALBASE}/lib
X11_CONFIGURE_ENABLE=	x11-textmode

PORTDOCS=	README
INFO=		hte

post-patch:
	@${REINPLACE_CMD} -e 's|^CXXFLAGS=.*$$|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|^CFLAGS=.*$$|CFLAGS="$$CFLAGS"|g ; \
		 s|-L/usr/X11/lib -L/usr/X11R6/lib|$$LDFLAGS|g' \
			${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ht ${STAGEDIR}${PREFIX}/bin/hte
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/hthelp.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}/hte.info

.include <bsd.port.mk>
