# Ports collection Makefile for:	veepee
# Date created:				2 August 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	veepee
PORTVERSION=	0.3
CATEGORIES=	devel python gnome
MASTER_SITES=	http://www.river-bank.demon.co.uk/software/
DISTNAME=	VeePee-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	python1.5:${PORTSDIR}/lang/python15
LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gd.1:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	python1.5:${PORTSDIR}/lang/python15

USE_XLIB=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS=	--with-gd-includes=${LOCALBASE}/include/gd \
		--disable-kde

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g' \
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
