# New ports collection makefile for:	Web1913 - JIS X 4081 format version
# Date created:        	00/06/19
# Whom:			Satoshi Taoka <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	web1913-fpw
PORTVERSION=	${WEB_VER}.${WEBFPW_VER}
CATEGORIES=	japanese
MASTER_SITES=	http://openlab.ring.gr.jp/edict/fpw/dist/web1913/ \
		ftp://ftp.dict.org/pub/dict/pre/
DISTNAME=	web1913-fpw${WEBFPW_VER}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		dict-web1913-${WEB_VER}-pre.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	taoka@FreeBSD.org

BUILD_DEPENDS=	fpwmake:${PORTSDIR}/japanese/freepwing \
		catdump:${PORTSDIR}/japanese/epwutil

WRKSRC=		${WRKDIR}/web1913-fpw${WEBFPW_VER}
WEBFPW_VER=	1.1.1
WEB_VER=	1.4

post-extract:
	cd ${WRKSRC}; \
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/dict-web1913-${WEB_VER}-pre.tar.gz \
		${EXTRACT_AFTER_ARGS}; \
	${GZIP_CMD} ${EXTRACT_BEFORE_ARGS} web1913.dict.dz > web1913.dict

post-patch:
	cd ${WRKSRC}; \
	${PATCH} ${PATCH_ARGS} < web1913.patch

do-build:
		cd ${WRKSRC}; \
		fpwmake ;\
		fpwmake catalogs
#		fpwmake > /dev/null; \

do-install:
	${MKDIR} ${PREFIX}/share/dict/web-fpw/web/data
	${INSTALL_DATA} ${WRKSRC}/honmon ${PREFIX}/share/dict/web-fpw/web/data
	${INSTALL_DATA} ${WRKSRC}/catalogs ${PREFIX}/share/dict/web-fpw
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/web-fpw
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/web-fpw
.endif

.include <bsd.port.mk>
