# Created by: ijliao@FreeBSD.org
# $FreeBSD$

PORTNAME=	log4cpp
DISTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}.x%20%28new%29/${PORTNAME}-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Library of C++ classes for flexible logging

USES=		gmake pathfix
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pthreads --disable-html-docs
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

.include <bsd.port.pre.mk>

# doxygen build is BROKEN atm
#.if exists (${LOCALBASE}/bin/doxygen) || !defined (NOPORTDOCS)
#BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
#.else
NOPORTDOCS=		true
CONFIGURE_ARGS+=	--disable-doxygen
#.endif

#.if !exists (${LOCALBASE}/bin/doxygen) && !defined (NOPORTDOCS)
#pre-everything::
#	@${ECHO_CMD}
#	@${ECHO_CMD} By default, this port uses doxygen to build its documentation.\
#It currently is not present your system, and if you do not want to install it, abort\
#this build by hitting CTRL+C and re-run the installation with -DNOPORTDOCS | ${FMT} 74
#	@${ECHO_CMD}
#	@sleep 3
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's| -pedantic||g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
