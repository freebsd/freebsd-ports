# Created by: William Lloyd <wlloyd@slap.net>
# $FreeBSD$

PORTNAME=	spandsp
DISTVERSION=	0.0.6pre21
PORTREVISION=	4
CATEGORIES=	comms
MASTER_SITES=	http://www.soft-switch.org/downloads/spandsp/
PKGNAMESUFFIX=	-devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DSP library and software FAX machine

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/spandsp-${DISTVERSION:C/pre.*//}

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
USES=		gmake libtool pathfix tar:tgz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFLICTS=	spandsp-[0-9]*

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Build and install documentation (requires doxygen)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
CONFIGURE_ARGS+=--enable-doc
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen \
		docbook-xsl>=0:${PORTSDIR}/textproc/docbook-xsl
USE_GNOME+=	libxslt
.else
CONFIGURE_ARGS+=--disable-doc
.endif

post-patch:
	@${REINPLACE_CMD} 's/tgmath\.h//' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-type d -or -mindepth 1")
.endif

.include <bsd.port.mk>
