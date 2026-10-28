PORTNAME=	caps-plugins
DISTVERSION=	0.9.26
CATEGORIES=	audio
MASTER_SITES=	http://quitte.de/dsp/
DISTNAME=	caps_${DISTVERSION}

MAINTAINER=	vishwin@FreeBSD.org
COMMENT=	The C* LADSPA Audio Plugin Suite
WWW=		http://quitte.de/dsp/caps.html

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake tar:bzip2

USE_CXXSTD=	c++11
WRKSRC=		${WRKDIR}/caps-${DISTVERSION}
MAKE_ARGS=	PREFIX=${PREFIX} DESTDIR=${STAGEDIR} CC="${CXX}" \
		CFLAGS="${CXXFLAGS} -fPIC -DPIC"

PLIST_FILES=	lib/ladspa/caps.so share/ladspa/rdf/caps.rdf

.include <bsd.port.mk>
