# ex:ts=8
# Ports collection makefile for:	K.R.S.S.
# Date created:			Apr 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	krss
PORTVERSION=	2.6
PORTREVISION=	3
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE Rich Site Summary viewer

WANT_AUTOMAKE_VER=14
WANT_AUTOCONF_VER=213
USE_KDEBASE_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBQT="-lqt-mt" KDB2HTML=${TRUE}

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

pre-configure:
	${MKDIR} ${WRKSRC}/auto-bin
	${LN} -sf ${AUTOCONF} ${WRKSRC}/auto-bin/autoconf
	${LN} -sf ${AUTOHEADER} ${WRKSRC}/auto-bin/autoheader
	${LN} -sf ${AUTOMAKE} ${WRKSRC}/auto-bin/automake
	${LN} -sf ${ACLOCAL} ${WRKSRC}/auto-bin/aclocal
	cd ${WRKSRC} && env PATH=${WRKSRC}/auto-bin:$$PATH \
		${GMAKE} -f Makefile.dist

.include <bsd.port.mk>
