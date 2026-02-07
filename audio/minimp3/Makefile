PORTNAME=	minimp3
DISTVERSION=	g20211130
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	audio
# Use direct link to 126KB files instead of 19+MB tarball:
# https://github.com/${GH_ACCOUNT}/${PORTNAME}/tar.gz/${GH_TAGNAME}?dummy=/${GH_ACCOUNT}-${PORTNAME}-${DISTVERSION}-${GH_TAGNAME}_GH0.tar.gz
MASTER_SITES=	https://raw.githubusercontent.com/${GH_ACCOUNT}/${PORTNAME}/${GH_TAGNAME}/
DISTFILES=	LICENSE minimp3.h minimp3_ex.h
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ single-header, minimalistic library for decoding MP3
WWW=		https://github.com/lieff/minimp3

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	nodefault
GH_ACCOUNT=	lieff
GH_TAGNAME=	afb604c06bc8beb145fecd42c0ceb5bda8795144

EXTRACT_CMD=		${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	${DISTFILES:M*.h:C|^|include/|}

do-install:
	${INSTALL_DATA} ${DISTFILES:M*.h:C|^|${WRKSRC}/|} \
		${STAGEDIR}${PREFIX}/include

.include <bsd.port.mk>
