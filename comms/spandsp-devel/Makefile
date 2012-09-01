# $FreeBSD$

PORTNAME=	spandsp
DISTVERSION=	0.0.6pre21
CATEGORIES=	comms
MASTER_SITES=	http://www.soft-switch.org/downloads/spandsp/ \
		http://www.soft-switch.org/downloads/spandsp/old/
PKGNAMESUFFIX=	-devel
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A DSP library and software FAX machine

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/spandsp-${DISTVERSION:C/pre.*//}
USE_AUTOTOOLS=	libtool autoconf
USE_GMAKE=	yes
USE_GNOME=	gnomehack

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		-C

USE_LDCONFIG=	yes

CONFLICTS=	spandsp-[0-9]*

OPTIONS_DEFINE=	DOXYGEN

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
CONFIGURE_ARGS+=--enable-doc
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
PORTDOCS=	*
.else
CONFIGURE_ARGS+=--disable-doc
.endif

post-install:
.if defined(WITH_DOXYGEN)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} \* ${DOCSDIR} "-type d -or -mindepth 1")
.endif

.include <bsd.port.mk>
