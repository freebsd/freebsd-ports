# Created by: Frank Mayhar <frank@exit.com>
# $FreeBSD$

PORTNAME=	kscope
PORTVERSION=	1.6.1
PORTREVISION=	7
CATEGORIES=	devel kde
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE front-end to Cscope

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	exctags:${PORTSDIR}/devel/ctags \
		cscope:${PORTSDIR}/devel/cscope \
		dot:${PORTSDIR}/graphics/graphviz

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

DOCSDIR=	${PREFIX}/share/doc/HTML/en/${PORTNAME}

USE_BISON=	build
USE_KDEBASE_VER=3
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes

MAKE_ENV=	EXTRA_LIBRARIES="-L${LOCALBASE}/lib"
LDFLAGS+=	${PTHREAD_LIBS}
CXXFLAGS+=	${PTHREAD_CFLAGS}
CONFIGURE_ARGS+=--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

.include <bsd.port.mk>
