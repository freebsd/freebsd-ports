# New ports collection makefile for:	premake4
# Date created:		2011-08-21
# Whom:			Vitaly Magerya <vmagerya@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	premake4
PORTVERSION=	4.3
CATEGORIES=	devel
MASTER_SITES=	SF/premake/Premake/${PORTVERSION}
DISTNAME=	premake-${PORTVERSION}-src

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Writes build scripts

WRKSRC=		${WRKDIR}/premake-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/build/gmake.unix

USE_ZIP=	yes
USE_GMAKE=	yes
MAKE_ARGS=	ARCH=""

PLIST_FILES=	bin/premake4

PORTDOCS=	CHANGES.txt LICENSE.txt README.txt

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's|-ldl||' ${BUILD_WRKSRC}/Premake4.make

do-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/release/premake4 ${PREFIX}/bin

.include <bsd.port.post.mk>
