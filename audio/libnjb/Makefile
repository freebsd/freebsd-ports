# Created by: adrianm
# $FreeBSD$

PORTNAME=	libnjb
PORTVERSION=	2.2.7
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library, API for communicating with Creative and Dell audio players

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pathfix ncurses libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	doxygen:devel/doxygen
DOCS_CONFIGURE_ENV_OFF=	ac_cv_prog_HAVE_DOXYGEN=no

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SHOW_DIRECTORIES/d' ${WRKSRC}/doc/Doxyfile.in
	@${REINPLACE_CMD} -e \
		'/pkgdocdir/s|-$$(VERSION)||g' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e 's|-lcurses|-lncurses|' ${WRKSRC}/configure \
		${WRKSRC}/sample/Makefile.am ${WRKSRC}/sample/Makefile.in

.include <bsd.port.mk>
