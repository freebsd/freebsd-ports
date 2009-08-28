# ex:ts=8
# Ports collection makefile for:	rexx-curl
# Date created:			Nov 11, 2003
# Whom:	      			ijliao
#
# $FreeBSD$
#

PORTNAME=	curl
PORTVERSION=	1.4
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	SF/rexx${PORTNAME}/rexx${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	rexx-
DISTNAME=	RexxCURL-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	External function package providing an interface to the cURL package

BUILD_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-regina
LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	rexx:${PORTSDIR}/lang/rexx-regina

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-rexx=regina
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/rexx${PORTNAME}
DATADIR=	${PREFIX}/share/rexx${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e "s| -lc | |g" -e "/\$(sharedir)\/images/d" \
		-e "/index.html/d" -e "/rxcurl64.png/d" ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/index.html ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/images/rxcurl64.png ${DOCSDIR}/images
.endif

.include <bsd.port.mk>
