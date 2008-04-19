# New ports collection makefile for:	ja-oleo
# Date created:		2 March 1997
# Whom:			Yoshiro MIHIRA
#
# $FreeBSD$
#

PORTNAME=	oleo
PORTVERSION=	1.99.16
PORTREVISION=	2
CATEGORIES=	japanese math
MASTER_SITES=	http://www.hh.iij4u.or.jp/~hayasida/oleo/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	oleo
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-doc.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Spreadsheet Program + Japanese patches

# xmkmf is for configure script, not for USE_IMAKE.
BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake

USE_BISON=	build

.if defined(WITH_MOTIF)
BUILD_DEPENDS+=	${LOCALBASE}/include/Xbae/Matrix.h:${PORTSDIR}/x11-toolkits/xbae
.else
CONFIGURE_ARGS+=--without-motif
.endif

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
GNU_CONFIGURE=	yes
INFO=		oleo

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Broken with gcc 4.2
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/ja_JP.EUC
	@${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/USING.eucJP ${DOCSDIR}/ja_JP.EUC
.endif

.include <bsd.port.post.mk>
