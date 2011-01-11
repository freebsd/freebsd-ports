# New ports collection makefile for:	edje
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	edje
DISTVERSION=	1.0.0.beta
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2010-10-03/base/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Edje is a complex graphical design and layout engine

LIB_DEPENDS=	lua-5.1:${PORTSDIR}/lang/lua

LICENSE=	BSD
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eet evas ecore embryo libtool_hack librt_hack
USE_EFL_EVAS_LOADERS=	eet jpeg png
USE_EFL_ECORE=	evas file imf imf_evas
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--without-vim

post-patch:
	@${REINPLACE_CMD} -E -e "/^SUBDIRS[[:space:]]+=/s/utils//" \
	    ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
