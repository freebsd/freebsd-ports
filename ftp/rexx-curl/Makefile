# Created by: ijliao
# $FreeBSD$

PORTNAME=	curl
PORTVERSION=	2.0
CATEGORIES=	ftp
MASTER_SITES=	SF/rexx${PORTNAME}/rexx${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	rexx-
DISTNAME=	RexxCURL-${PORTVERSION}

MAINTAINER=	bob@eager.cx
COMMENT=	External function package providing an interface to the cURL package

LICENSE=	CPLV1
LICENSE_NAME=	CPL V1.0 license
LICENSE_FILE=	${WRKSRC}/CPLv1.0.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	rexx:lang/rexx-regina
LIB_DEPENDS=	libcurl.so:ftp/curl \
		libregina.so:lang/rexx-regina
RUN_DEPENDS=	rexx:lang/rexx-regina

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-rexx=regina
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/rexx${PORTNAME}
DATADIR=	${PREFIX}/share/rexx${PORTNAME}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e "s| -lc | |g" \
		-e "/\$.sharedir)\/images/d" \
		-e "/index.html/d" \
		-e "/rxcurl64.png/d" \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rexxcurl
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librexxcurl.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/index.html ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/images
	${INSTALL_DATA} ${WRKSRC}/doc/images/rxcurl64.png ${STAGEDIR}${DOCSDIR}/images

.include <bsd.port.mk>
