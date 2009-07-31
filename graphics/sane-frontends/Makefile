# New ports collection makefile for:	sane-frontends
# Date created:			Sat Jul 19 16:23:10 MET DST 1997
# Whom:				gary@hotlava.com
#
# $FreeBSD$
#

PORTNAME=	sane-frontends
PORTVERSION=	1.0.14
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://alioth.debian.org/frs/download.php/1140/ \
		ftp://ftp.sane-project.org/pub/sane/%SUBDIR%/ \
		ftp://ftp2.sane-project.org/pub/sane/%SUBDIR%/ \
		ftp://ftp3.sane-project.org/pub/sane/%SUBDIR%/ \
		ftp://gd.tuwien.ac.at/hci/sane/%SUBDIR%/ \
		http://gd.tuwien.ac.at/hci/sane/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tools for access to scanners, digitals camera, frame grabbers etc

LIB_DEPENDS=	sane.1:${PORTSDIR}/graphics/sane-backends

USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		scanadf.1 xcam.1 xscanimage.1

OPTIONS=	GTK1 "GTK1 support (Default is GTK2)" off \
		GIMP "also build xscanimage as a GIMP plug-in" off

.include <bsd.port.pre.mk>

.if defined(WITH_GTK1)
USE_GNOME+=	gtk12
CONFIGURE_ARGS+=	--disable-gtk2
.if defined(WITH_GIMP)
LIB_DEPENDS+=	gimp:${PORTSDIR}/graphics/gimp1
CONFIGURE_ARGS+=	--enable-gimp12
.else
CONFIGURE_ARGS+=	--disable-gimp
.endif
.else
USE_GNOME+=	gtk20
.if defined(WITH_GIMP)
LIB_DEPENDS+=	gimp-2.0:${PORTSDIR}/graphics/gimp
CONFIGURE_ARGS+=	--enable-gimp
.else
CONFIGURE_ARGS+=	--disable-gimp
.endif
.endif

post-install:
	@${SED} 's:/usr/local:${PREFIX}:' ${PKGMESSAGE}

.include <bsd.port.post.mk>
