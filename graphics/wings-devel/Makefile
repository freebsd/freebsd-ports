# New ports collection makefile for:	wings
# Date Created:				5 March 2003
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	wings
PORTVERSION=	0.98.17f
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	wings
DIST_SUBDIR=	erlang

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	A polygon mesh modeler written in Erlang

BUILD_DEPENDS=	erlc:${PORTSDIR}/lang/erlang \
		${LOCALBASE}/lib/erlang/lib/esdl/include/sdl.hrl:${PORTSDIR}/devel/esdl
RUN_DEPENDS=	erl:${PORTSDIR}/lang/erlang \
		${LOCALBASE}/lib/erlang/lib/esdl/include/sdl.hrl:${PORTSDIR}/devel/esdl

MAKE_ENV=	ESDL_PATH=${LOCALBASE}/lib/erlang/lib/esdl
PLIST_SUB=	VERSION="${PORTVERSION}"
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes

post-patch:
	@${CP} ${FILESDIR}/wings.sh ${WRKSRC}/wings.sh
	@${REINPLACE_CMD} -e 's|!!PREFIX!!|${PREFIX}|g' ${WRKSRC}/wings.sh
	@${FIND} ${WRKSRC} -name *.orig | ${XARGS} ${RM}

do-install:
	@${MKDIR} ${PREFIX}/lib/erlang/lib/${DISTNAME}
	@${MKDIR} ${PREFIX}/lib/erlang/lib/${DISTNAME}/src
	@${MKDIR} ${PREFIX}/lib/erlang/lib/${DISTNAME}/ebin
	@${MKDIR} ${PREFIX}/lib/erlang/lib/${DISTNAME}/plugins
	@${INSTALL_DATA} ${WRKSRC}/src/* ${PREFIX}/lib/erlang/lib/${DISTNAME}/src
	@${INSTALL_DATA} ${WRKSRC}/ebin/* ${PREFIX}/lib/erlang/lib/${DISTNAME}/ebin
	@${CP} -r ${WRKSRC}/plugins/* ${PREFIX}/lib/erlang/lib/${DISTNAME}/plugins
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/erlang/lib/${DISTNAME}/plugins
	@${INSTALL_SCRIPT} ${WRKSRC}/wings.sh ${PREFIX}/bin/wings
	@${LN} -sf ${DISTNAME} ${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.mk>
