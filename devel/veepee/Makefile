# Ports collection Makefile for:	veepee
# Date created:				2 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	veepee
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	devel python gnome
MASTER_SITES=	http://www.river-bank.demon.co.uk/software/
DISTNAME=	VeePee-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gd.2:${PORTSDIR}/graphics/gd

USE_XLIB=	yes
USE_PYTHON=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS} ${PYTHON_LIBS}"
CONFIGURE_ARGS=	--with-gd-includes=${LOCALBASE}/include/gd \
		--disable-kde
.if exists(/usr/lib/libcrypto.a)
PYTHON_LIBS+=	-lssl -lcrypto
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/configure

post-configure:
	@${PERL} -pi -e 's|^deplibs_check_method=.*|deplibs_check_method=pass_all|' \
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
