# Created by: adrianm
# $FreeBSD$

PORTNAME=	libnjb
PORTVERSION=	2.2.7
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library, API for communicating with Creative and Dell audio players

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS_DEFINE=	DOCS

USES=	pathfix
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.else
CONFIGURE_ENV+=	ac_cv_prog_HAVE_DOXYGEN=no
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/^SHOW_DIRECTORIES/d' ${WRKSRC}/doc/Doxyfile.in
	@${REINPLACE_CMD} -e \
		'/pkgdocdir/s|-$$(VERSION)||g' ${WRKSRC}/doc/Makefile.in

.include <bsd.port.mk>
