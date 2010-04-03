# ex:ts=8
# Ports collection makefile for:	curlpp
# Date created:			Nov 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	curlpp
PORTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE} \
		http://rrette.com/files/curlpp/curlpp-${PORTVERSION:R}/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A C++ wrapper for libcurl

LIB_DEPENDS=	curl.6:${PORTSDIR}/ftp/curl

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-ewarning --without-boost
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/example*.cpp ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/guide.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
