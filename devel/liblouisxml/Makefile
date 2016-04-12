# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblouisxml
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Library Provide Complete Braille Transcription Services

LICENSE=	LGPL3+ GPLv3+
LICENSE_COMB=	multi

RUN_DEPENDS=	${LOCALBASE}/bin/bash:shells/bash
LIB_DEPENDS=	liblouis.so:devel/liblouis

GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
USE_GCC=	yes

INFO=		liblouisxml

OPTIONS_DEFINE=	DOCS

post-extract:
	@${REINPLACE_CMD} -e \
		's#@libdir@#${PREFIX}/libdata#g' ${WRKSRC}/Makefile.in

post-build:
.for i in msword2brl xml2brl pdf2brl rtf2brl
	@${REINPLACE_CMD} -e 's#/bin/bash#${LOCALBASE}/bin/bash#g' ${WRKSRC}/tools/${i}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/liblouisxml.info ${STAGEDIR}${PREFIX}/info

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in liblouisxml.html liblouisxml.txt
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
