# New ports collection makefile for:	vflib + FreeType
# Date created:		10 May 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vflib
PORTVERSION=	2.25.6
PORTREVISION=	11
CATEGORIES=	japanese print
MASTER_SITES=	ftp://gull.se.hiroshima-u.ac.jp/pub/TypeHack/
DISTNAME=	VFlib2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese Vector font library

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake
RUN_DEPENDS=	${LOCALBASE}/share/font-sazanami/sazanami-mincho.ttf:${PORTSDIR}/japanese/font-sazanami

USE_XORG=	x11 xext
USE_FREETYPE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	autoconf:213
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-freetype \
		--with-freetype-includedir=${LOCALBASE}/include/freetype1/freetype \
		--with-freetype-libdir=${LOCALBASE}/lib
PLIST_SUB=	ETCDIR=${ETCDIR}

PORTDOCS=	${PORTDOCS_WRKSRC} ${PORTDOCS_WRKSRC_DOC}
PORTDOCS_WRKSRC=	COPYING COPYING.LIB README.txt.JP_EUC
PORTDOCS_WRKSRC_DOC=	QA.txt QA-english.tex man.ps man.dvi
ETCDIR=		etc/vflib

post-install:
	cd ${WRKSRC}/tools && \
		${INSTALL_SCRIPT} fmtest disol kban vfperf vftest \
			${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/jTeX ${DATADIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS_WRKSRC} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} ${PORTDOCS_WRKSRC_DOC} ${DOCSDIR}
.endif

post-install:

.include <bsd.port.mk>
