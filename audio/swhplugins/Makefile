# New ports collection Makefile for: 	swhplugins
# Date created:			12 May 2002
# Whom:				Tilman Linneweh <arved@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=		swhplugins
PORTVERSION=		0.3.0
CATEGORIES=		audio
MASTER_SITES=		http://plugin.org.uk/releases/${PORTVERSION}/
DISTNAME=		swh-plugins-${PORTVERSION}

MAINTAINER=		arved@FreeBSD.org

BUILD_DEPENDS=		${LOCALBASE}/include/ladspa.h:${PORTSDIR}/audio/ladspa \
			autoconf:${PORTSDIR}/devel/autoconf
LIB_DEPENDS=		fftw.2:${PORTSDIR}/math/fftw

AUTOCONF=		${LOCALBASE}/bin/autoconf
USE_AUTOMAKE=		yes
AUTOMAKE_VER=		14
AUTOMAKE_ARGS=		--add-missing --foreign
INSTALLS_SHLIB=		yes
USE_REINPLACE=		yes
USE_GMAKE=		yes

pre-extract:
	@${ECHO_CMD} "NOTE: This port does not build all \
			Plugins, due to missing lrintf() function on FreeBSD"

post-patch:
	${REINPLACE_CMD} -e "s,-Bsymbolic,-Bsymbolic -L${LOCALBASE}/lib," \
		${WRKSRC}/Makefile.am
	cd ${WRKSRC} && ${AUTOCONF}

.include <bsd.port.mk>
