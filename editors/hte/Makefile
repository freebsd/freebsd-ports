# Created by: Ying-Chieh Liao
# $FreeBSD$

PORTNAME=	hte
PORTVERSION=	2.1.0
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/ht-source
DISTNAME=	ht-${PORTVERSION}

MAINTAINER=	rene@FreeBSD.org
COMMENT=	File editor/viewer/analyzer for executables

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses tar:bzip2
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/hte
PORTDOCS=	README
INFO=		hte

OPTIONS_DEFINE=		DOCS LZO2 X11
OPTIONS_DEFAULT=	X11

LZO2_DESC=	External lzo2 compression support
LZO2_LIB_DEPENDS=	liblzo2.so:archivers/lzo2
LZO2_CONFIGURE_OFF=	--with-included-lzo

X11_DESC=	X11 textmode support
X11_USE=		XORG=x11
X11_USES=		localbase:ldflags
X11_CONFIGURE_ENABLE=	x11-textmode

post-patch:
	@${REINPLACE_CMD} -e 's|^CXXFLAGS=.*$$|CXXFLAGS="$$CXXFLAGS"|g ; \
		 s|^CFLAGS=.*$$|CFLAGS="$$CFLAGS"|g ; \
		 s|-L/usr/X11/lib -L/usr/X11R6/lib|$$LDFLAGS|g' \
			${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ht ${STAGEDIR}${PREFIX}/bin/hte
	${INSTALL_DATA} ${WRKSRC}/doc/hthelp.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}/hte.info

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
