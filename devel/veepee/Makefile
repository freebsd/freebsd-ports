# Ports collection Makefile for:	veepee
# Date created:				2 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	veepee
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	devel python gnome
MASTER_SITES=	http://www.river-bank.demon.co.uk/software/
DISTNAME=	VeePee-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A user orientated scripting environment for embedding in applications

BROKEN=		"fails to compile"

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

USE_GNOME=	gnomelibs
USE_XLIB=	yes
USE_PYTHON=	yes
USE_LIBTOOL=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS} ${PYTHON_LIBS}"
CONFIGURE_ARGS=	--with-gd-includes=${LOCALBASE}/include \
		--disable-kde
.if exists(/usr/lib/libcrypto.a)
PYTHON_LIBS+=	-lssl -lcrypto
.endif

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|#include <values.h>||g' \
		${WRKSRC}/pymod/gdchart/gdc_pie.c

post-configure:
	@${REINPLACE_CMD} -e \
		's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
		${WRKSRC}/libtool

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/veepee
	${MKDIR} ${PREFIX}/share/examples/veepee
	cd ${WRKSRC}/doc && \
		${INSTALL_DATA} GNOMEapi.txt controls.txt ${PREFIX}/share/doc/veepee
	cd ${WRKSRC}/examples && \
		${INSTALL_SCRIPT} *.py ${PREFIX}/share/examples/veepee
.endif

.include <bsd.port.mk>
