# New ports collection makefile for:	gimp-focusblur
# Date created:		03 Jun 2009
# Whom:			Denis Barov <dindin@dindin.ru>
#
# $FreeBSD$
#

PORTNAME=	focusblur
PORTVERSION=	3.2.4
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://sudakyo.hp.infoseek.co.jp/gimp/fblur/ \
		http://www.dindin.ru/download/
PKGNAMEPREFIX=	gimp-
PKGNAMESUFFIX=	-plugin

MAINTAINER=	dindin@dindin.ru
COMMENT=	Gimp realistic focus blur plugin

LIB_DEPENDS=	gimp-2.0:${PORTSDIR}/graphics/gimp-app \
		fftw3.5:${PORTSDIR}/math/fftw3

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
MAKE_JOBS_SAFE=	yes

PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins
PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--disable-rpath

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^bindir = .*|bindir = ${PREFIX}/${PLUGIN_DIR}|g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
