# New ports collection makefile for:	ja-oleo
# Date created:		2 March 1997
# Whom:			Yoshiro MIHIRA
#
# $FreeBSD$
#

PORTNAME=	oleo
PORTVERSION=	1.99.16
CATEGORIES=	japanese math
MASTER_SITES=	http://www.hh.iij4u.or.jp/~hayasida/oleo/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	oleo
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-doc.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Spreadsheet Program + Japanese patches

# xmkmf is for configure script, not for USE_IMAKE.
BUILD_DEPENDS=	xmkmf:${X_IMAKE_PORT} \
		bison:${PORTSDIR}/devel/bison

.if defined(WITH_MOTIF)
BUILD_DEPENDS+=	${LOCALBASE}/include/Xbae/Matrix.h:${PORTSDIR}/x11-toolkits/xbae
.else
CONFIGURE_ARGS+=--without-motif
.endif

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
GNU_CONFIGURE=	yes
USE_XLIB=	yes

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/ja_JP.EUC
	@${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/USING.eucJP ${DOCSDIR}/ja_JP.EUC
.endif

.include <bsd.port.post.mk>
