# New ports collection makefile for:	glimmer
# Date created:				1 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	glimmer
PORTVERSION=	1.2.1
PORTREVISION=	3
CATEGORIES=	editors gnome python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A full featured code editor for GNOME desktop with many advanced features

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gnomeprint gnomevfs
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-regex
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -D_REGEX_H_ -D_REGEX_H" \
		LIBS="-L${LOCALBASE}/lib -lgnuregex"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
.if exists(/usr/lib/libcrypto.a)
PYTHON_LIBS=	-lssl -lcrypto
.endif
PYTHON_LIBS+=	-lutil -lreadline -lcrypt -lpython

post-patch:
	@${REINPLACE_CMD} -e 's|-lpython|${PYTHON_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
