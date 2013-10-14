# Created by: nork@FreeBSD.org
# $FreeBSD$

PORTNAME=	openexr_ctl
PORTVERSION=	1.0.1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/ampasctl/${PORTNAME}/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Simplified OpenEXR interface to CTL

LICENSE=	BSD

LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		IlmCtl:${PORTSDIR}/graphics/ampasCTL

USES=		pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes

DEPRECATED=	Now distributed with ampasCTL-1.5
EXPIRATION_DATE=2013-12-13

PORTDOCS=	AUTHORS ChangeLog README

NO_STAGE=	yes
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
