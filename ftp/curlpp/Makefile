# ex:ts=8
# Ports collection makefile for:	curlpp
# Date created:			Nov 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	curlpp
PORTVERSION=	0.3.0
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ wrapper for libcurl

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash2
LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

.if ${OSVERSION} < 500035
USE_GCC=	3.1
.else
CONFIGURE_ENV+=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|^#! /bin/sh|#!${LOCALBASE}/bin/bash|" ${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} ${WRKSRC}/test/README ${EXAMPLESDIR}
	@${CP} ${WRKSRC}/test/example*.cpp ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
