# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	glimmer
PORTVERSION=	1.2.1
PORTREVISION=	13
CATEGORIES=	editors gnome python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-source/${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A full featured code editor for GNOME with many advanced features

DEPRECATED=	Depends on the expired gtkglarea through py-gtk
EXPIRATION_DATE=	2012-11-28

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-1.2/_gtkmodule.so:${PORTSDIR}/x11-toolkits/py-gtk

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_PYTHON=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gnomeprint gnomevfs \
		gnomeprefix
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-regex
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lgnuregex"
CPPFLAGS+=	-I${LOCALBASE}/include -I/usr/include/gnu

.if exists(/usr/lib/libcrypto.a)
PYTHON_LIBS=	-lssl -lcrypto
.endif
PYTHON_LIBS+=	-lutil -lreadline -lcrypt -lpython

post-patch:
	@${REINPLACE_CMD} -e 's|-lpython|${PYTHON_LIBS}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|gnuregex\.h|regex.h|' \
		${WRKSRC}/src/gtkextext/gtkextext.h

.include <bsd.port.mk>
