# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblouisxml
PORTVERSION=	2.4.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Library Provide Complete Braille Transcription Services

LICENSE=	GPLv3

RUN_DEPENDS=	${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
LIB_DEPENDS=	liblouis.so:${PORTSDIR}/devel/liblouis

GNU_CONFIGURE=	yes
USES=		pkgconfig gmake libtool
USE_LDCONFIG=	yes
USE_GNOME=	libxml2
USE_GCC=	yes

INFO=		liblouisxml

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-extract:
	@${REINPLACE_CMD} -e \
		's#@libdir@#${PREFIX}/libdata#g' ${WRKSRC}/Makefile.in

post-build:
.for i in msword2brl xml2brl pdf2brl rtf2brl
	@${REINPLACE_CMD} -e 's#/bin/bash#${LOCALBASE}/bin/bash#g' ${WRKSRC}/tools/${i}
.endfor

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in liblouisxml.html liblouisxml.txt
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${STAGEDIR}${DOCSDIR}/
.endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/liblouisxml.info ${STAGEDIR}${PREFIX}/info

.include <bsd.port.mk>
