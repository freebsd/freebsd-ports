# ex:ts=8
# Ports collection makefile for:	curlpp
# Date created:			Nov 27, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	curlpp
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	roam@FreeBSD.org
COMMENT=	A C++ wrapper for libcurl

LIB_DEPENDS=	curl.2:${PORTSDIR}/ftp/curl

USE_GCC=	3.3
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-ewarning
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha" && ${OSVERSION} < 500000
BROKEN=		"Does not compile on alpha 4.x"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/README ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test/example*.cpp ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
