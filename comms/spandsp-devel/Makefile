# New ports collection makefile for:	spandsp-devel
# Date created:		2007-01-13
# Whom:			Joe Holden <joe@joeholden.co.uk>
#
# $FreeBSD$
#

PORTNAME=	spandsp
DISTVERSION=	0.0.6pre12
CATEGORIES=	comms
MASTER_SITES=	http://www.soft-switch.org/downloads/spandsp/ \
		ftp://ftp.rewt.org.uk/pub/distfiles/
PKGNAMESUFFIX=	-devel
EXTRACT_SUFX=	.tgz

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	A DSP library and software FAX machine

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff

WRKSRC=		${WRKDIR}/spandsp-${DISTVERSION:C/pre.*//}
USE_AUTOTOOLS=	libtool15
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

USE_LDCONFIG=	yes

CONFLICTS=	spandsp-[0-9]*

.ifndef(WITH_DOXYGEN)
NOPORTDOCS=	yes
CONFIGURE_ARGS+=--disable-doc
.else
CONFIGURE_ARGS+=--enable-doc
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
.endif

post-configure:
	${REINPLACE_CMD} -e 's/\/pkgconfig/data\/pkgconfig/' ${WRKSRC}/Makefile

post-install:
.if defined(WITH_DOXYGEN)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR} "-type d -or -mindepth 1")
PORTDOCS=	*
.endif

.include <bsd.port.mk>
