# New ports collection makefile for:	esdl
# Date Created:				2 January 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	esdl
PORTVERSION=	0.91.1129
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_THEMES}
MASTER_SITE_SUBDIR=	esdl
DISTNAME=	esdl-${PORTVERSION}.src

MAINTAINER=	olgeni@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_GMAKE=	yes

ESDL_PATH=	${PREFIX}/lib/erlang/lib/esdl-${PORTVERSION}

do-build:
		@cd ${WRKSRC}/c_src && ${GMAKE}
		@cd ${WRKSRC}/test && ${GMAKE}

do-install:
		@${MKDIR} ${ESDL_PATH}
		@${MKDIR} ${ESDL_PATH}/doc
		@${MKDIR} ${ESDL_PATH}/ebin
		@${MKDIR} ${ESDL_PATH}/include
		@${MKDIR} ${ESDL_PATH}/priv
		@${MKDIR} ${ESDL_PATH}/src
		@${FIND} ${ESDL_PATH} -type d | ${XARGS} ${CHMOD} 755

		@${INSTALL_DATA} ${WRKSRC}/doc/* ${ESDL_PATH}/doc
		@${INSTALL_DATA} ${WRKSRC}/ebin/* ${ESDL_PATH}/ebin
		@${INSTALL_DATA} ${WRKSRC}/include/* ${ESDL_PATH}/include
		@${INSTALL_DATA} ${WRKSRC}/priv/sdl_driver.so ${ESDL_PATH}/priv
		@${INSTALL_PROGRAM} ${WRKSRC}/priv/sdlwrapper ${ESDL_PATH}/priv
		@${INSTALL_DATA} ${WRKSRC}/src/* ${ESDL_PATH}/src

		@${CP} -r ${WRKSRC}/priv ${ESDL_PATH}
		@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${ESDL_PATH}

.include <bsd.port.mk>
