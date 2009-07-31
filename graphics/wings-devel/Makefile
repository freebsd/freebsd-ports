# New ports collection makefile for:	wings
# Date Created:				5 March 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	wings
PORTVERSION=	0.99.04a
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	SF
DIST_SUBDIR=	erlang

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A polygon mesh modeler written in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		${LOCALBASE}/lib/erlang/lib/esdl/include/sdl.hrl:${PORTSDIR}/devel/esdl
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		${LOCALBASE}/lib/erlang/lib/esdl/include/sdl.hrl:${PORTSDIR}/devel/esdl

MAKE_ENV=	ESDL_PATH=${LOCALBASE}/lib/erlang/lib/esdl
PLIST_SUB=	VERSION="${PORTVERSION}"

SUB_FILES=	wings.sh

USE_BZIP2=	yes
USE_GMAKE=	yes

BROKEN=		Broken with erlang-r13b

post-patch:
	@${REINPLACE_CMD} -e 's|$$(GCC)|${CC} -I${LOCALBASE}/include -L${LOCALBASE}/lib|g' \
		${WRKSRC}/plugins_src/accel/Makefile

do-install:
	${MKDIR} ${PREFIX}/lib/erlang/lib/${DISTNAME}
.for dir in src ebin fonts plugins
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${dir} ${PREFIX}/lib/erlang/lib/${DISTNAME}
.endfor
	@${INSTALL_SCRIPT} ${WRKDIR}/wings.sh ${PREFIX}/bin/wings
	@${LN} -sf ${DISTNAME} ${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.mk>
