# New ports collection makefile for:	openexr_ctl
# Date created:				2007-10-09
# Whom:					nork@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	openexr_ctl
PORTVERSION=	1.0.1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/ampasctl/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simplified OpenEXR interface to CTL

LICENSE=	BSD

LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		IlmCtl:${PORTSDIR}/graphics/ampasCTL

USE_PKGCONFIG=	build
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

PORTDOCS=	AUTHORS ChangeLog README

.include <bsd.port.options.mk>

test check:	build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check)

.if defined(PACKAGE_BUILDING)
pre-install:	test
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
