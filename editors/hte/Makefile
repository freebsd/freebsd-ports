# Created by: Ying-Chieh Liao
# $FreeBSD$

PORTNAME=	hte
PORTVERSION=	2.1.1.g20161206
PORTREVISION=	3
CATEGORIES=	editors

MAINTAINER=	rene@FreeBSD.org
COMMENT=	File editor/viewer/analyzer for executables

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++14-lang makeinfo ncurses tar:bzip2
USE_GITHUB=	yes
GH_ACCOUNT=	sebastianbiallas
GH_PROJECT=	ht
GH_TAGNAME=	e9e63373148da5d7df397d8075740d8c096ecb1d
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
X11_USES=		localbase:ldflags xorg
X11_USE=		XORG=x11
X11_CONFIGURE_ENABLE=	x11-textmode

MAKE_JOBS_UNSAFE=	yes

pre-build:
	${MAKE} -C ${WRKSRC}/tools
	${MAKE} -C ${WRKSRC}/doc
	${MAKE} -C ${WRKSRC} htdoc.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ht ${STAGEDIR}${PREFIX}/bin/hte
	${INSTALL_DATA} ${WRKSRC}/doc/hthelp.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH}/hte.info

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
