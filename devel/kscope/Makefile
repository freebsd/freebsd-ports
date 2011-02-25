# New ports collection makefile for:	kscope
# Date created:		2004-04-21
# Whom:			Frank Mayhar <frank@exit.com>
#
# $FreeBSD$
#

PORTNAME=	kscope
PORTVERSION=	1.6.1
PORTREVISION=	6
CATEGORIES=	devel kde
MASTER_SITES=	SF

MAINTAINER=	frank@exit.com
COMMENT=	KDE front-end to Cscope

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags \
		cscope:${PORTSDIR}/devel/cscope \
		dot:${PORTSDIR}/graphics/graphviz

DOCSDIR=	${PREFIX}/share/doc/HTML/en/${PORTNAME}

USE_BISON=	build
USE_KDEBASE_VER=3
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
INSTALLS_ICONS=	yes

MAKE_ENV=	EXTRA_LIBRARIES="-L${LOCALBASE}/lib"
CONFIGURE_ENV=	CXXFLAGS="${PTHREAD_CFLAGS}" LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

.include <bsd.port.mk>
