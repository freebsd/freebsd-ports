# New ports collection makefile for:	 gnotepad+
# Date created:		08 March 1999
# Whom:			brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	gnotepad+
PORTVERSION=	1.3.0
CATEGORIES=	editors www
MASTER_SITES=	http://download.sourceforge.net/gnotepad/
.if !defined(NOPORTDOCS)
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-help-${DOCVERSION}${EXTRACT_SUFX}
.endif

MAINTAINER=	brett@peloton.runet.edu

LIB_DEPENDS=    gnome.3:${PORTSDIR}/x11/gnomelibs

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

DOCVERSION=	1.2.0
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	GTK_CONFIG="${GTK_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=	gnp.1

.if !defined(NOPORTDOCS)
post-extract:
	@${MV} ${WRKSRC}/docs ${WRKSRC}/docs.old
	@${CP} -R ${WRKDIR}/${PORTNAME}-help-${DOCVERSION}/docs ${WRKSRC}/docs
.endif

.include <bsd.port.mk>
