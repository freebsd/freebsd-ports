# ex:ts=8
# Ports collection makefile for:	curlpp
# Date created:			Nov 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	curlpp
PORTVERSION=	0.5.2
CATEGORIES=	ftp
MASTER_SITES=	http://rrette.com/downloads/sources/

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A C++ wrapper for libcurl

LIB_DEPENDS=	curl.3:${PORTSDIR}/ftp/curl

USE_GCC=	3.4
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-ewarning
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
BROKEN=		"Does not compile on alpha 4.x"
.endif

pre-everything::
	@${ECHO} ""
	@${ECHO} "NOTE to people using 0.3.x: cURLpp 0.3.x is dead!"
	@${ECHO} "The current version ${PORTVERSION} is incompatible with the old 0.3.x versions"
	@${ECHO} ""

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

.include <bsd.port.post.mk>
