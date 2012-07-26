# New ports collection makefile for:	liblouisxml
# Date created:				06 Feb 2009
# Whom:					Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	liblouisxml
PORTVERSION=	1.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	wenheping@gmail.com
COMMENT=	Library Provide Complete Braille Transcription Services

LIB_DEPENDS=	louis.2:${PORTSDIR}/devel/liblouis \
		xml2.5:${PORTSDIR}/textproc/libxml2

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_PKGCONFIG=	yes

INFO=		liblouisxml-guide
MAN1=		msword2brl.1 xml2brl.1

post-extract:
	@${REINPLACE_CMD} -e \
		's#@libdir@#${PREFIX}/libdata#g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's#doc lbx_files#lbx_files#g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in liblouisxml-guide.html liblouisxml-guide.txt copyright-notice \
	example_canonical.cfg example_default.cfg example_html.sem example_math.sem
	${INSTALL_MAN} ${WRKSRC}/doc/${i} ${DOCSDIR}/
.endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/doc/liblouisxml-guide.info ${PREFIX}/info
	${INSTALL_MAN} ${WRKSRC}/doc/msword2brl.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/xml2brl.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
