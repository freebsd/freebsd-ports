# ex:ts=8
# Ports collection makefile for:	K.R.S.S.
# Date created:			Apr 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	krss
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE Rich Site Summary viewer

BUILD_DEPENDS=	autoconf213:${PORTSDIR}/devel/autoconf213 \
		automake14:${PORTSDIR}/devel/automake14

USE_KDEBASE_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBQT="-lqt-mt"

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
.for AC in autoconf autoheader
	${LN} -sf ${LOCALBASE}/bin/${AC}213 ${WRKSRC}/auto-bin/${AC}
.endfor
.for AM in automake aclocal
	${LN} -sf ${LOCALBASE}/bin/${AM}14 ${WRKSRC}/auto-bin/${AM}
.endfor
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.dist

.include <bsd.port.mk>
