# Created by: Tilman Linneweh <arved@FreeBSD.org>

PORTNAME=	swhplugins
PORTVERSION=	0.4.17
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Steve Harris' huge Collection of LADSPA Plugins

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/ladspa.h:audio/ladspa \
		${LOCALBASE}/include/fftw3.h:math/fftw3 \
		p5-XML-Parser>=0:textproc/p5-XML-Parser
LIB_DEPENDS=	libfftw3f.so:math/fftw3-float

USES=		autoreconf gmake libtool localbase:ldflags pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	swh
GH_PROJECT=	ladspa
SHEBANG_FILES=	makestub.pl

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CFLAGS+=	-fPIC -DPIC -fgnu89-inline

OPTIONS_DEFINE=	NLS 3DNOW SSE
OPTIONS_SUB=	yes
3DNOW_DESC=	use 3DNow! instructions
SSE_DESC=	use SSE instructions

NLS_USES=	gettext
NLS_LDFLAGS=	-lintl
NLS_CONFIGURE_ENABLE=	nls
NLS_USES_OFF=	gettext-tools

3DNOW_CONFIGURE_ENABLE=	3dnow

SSE_CONFIGURE_ENABLE=	sse

.include <bsd.port.mk>
