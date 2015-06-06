# Created by: ijliao@FreeBSD.org
# $FreeBSD$

PORTNAME=	log4cpp
DISTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}.x%20%28new%29/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library of C++ classes for flexible logging

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake libtool pathfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pthreads --disable-html-docs
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

# doxygen build is BROKEN atm
#.if exists (${LOCALBASE}/bin/doxygen) || ${PORT_OPTIONS:MDOCS}
#BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
#.else
CONFIGURE_ARGS+=	--disable-doxygen
#.endif

#.if !exists (${LOCALBASE}/bin/doxygen) && ${PORT_OPTIONS:MDOCS}
#pre-everything::
#	@${ECHO_CMD}
#	@${ECHO_CMD} By default, this port uses doxygen to build its documentation.\
#It currently is not present your system, and if you do not want to install it, abort\
#this build by hitting CTRL+C and re-run the installation with OPTIONS_UNSET=DOCS | ${FMT} 74
#	@${ECHO_CMD}
#	@sleep 3
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's| -pedantic||g' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib${PORTNAME}.so

.include <bsd.port.mk>
