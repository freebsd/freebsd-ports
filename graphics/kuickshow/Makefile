# New ports collection makefile for:	kuickshow
# Date created:		5 May 2001
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	kuickshow
PORTVERSION=	0.8.1
CATEGORIES=	graphics
MASTER_SITES=	http://master.kde.org/~pfeiffer/kuickshow/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@fix.no

GNU_CONFIGURE=	yes

USE_KDELIBS_VER=	2
USE_GMAKE=	yes

CONFIGURE_ENV+=	LIBQT="-lqt2" MOC="moc2" KDEDIR="${LOCALBASE}"
CONFIGURE_ARGS+=	--with-qt-includes=${X11BASE}/include/qt2 \
			--with-qt-libraries=${X11BASE}/lib \
			--with-imlib-config=${X11BASE}/bin

.if !defined(NOPORTDOCS)
post-install:
	@(cd ${WRKSRC}/doc && ${GMAKE} real-install)
.endif

.include <bsd.port.mk>
