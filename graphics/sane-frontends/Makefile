# New ports collection makefile for:	sane-frontends
# Date created:			Sat Jul 19 16:23:10 MET DST 1997
# Whom:				gary@hotlava.com
#
# $FreeBSD$
#

PORTNAME=	sane-frontends
PORTVERSION=	1.0.6
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mostang.com/pub/sane/%SUBDIR%/ \
		ftp://ftp.de.mostang.com/pub/sane/%SUBDIR%/ \
		ftp://ftp.no.mostang.com/pub/sane/%SUBDIR%/
MASTER_SITE_SUBDIR=	sane-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	sane.1:${PORTSDIR}/graphics/sane-backends

USE_GTK=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		xcam.1 xscanimage.1

.if defined(WITH_GIMP)
LIB_DEPENDS+=	gimp:${PORTSDIR}/graphics/gimp1
CONFIGURE_ARGS+=	--enable-gimp
.else
CONFIGURE_ARGS+=	--disable-gimp
.endif

pre-everything::
.if !defined(WITH_GIMP)
	@${ECHO_MSG} "*** Note: xscanimage can be built with a standalone"
	@${ECHO_MSG} "*** X scanner interface as well as a GIMP plug-in."
	@${ECHO_MSG} "*** If you wish to do this, hit Ctrl-C now and use"
	@${ECHO_MSG} "*** \"WITH_GIMP=yes\""
.endif

post-install:
	@${SED} 's:/usr/local:${PREFIX}:' ${PKGMESSAGE}

.include <bsd.port.mk>
