PORTNAME=	sox-noise
PORTVERSION=	g20241022
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Noise generator GUI powered by Sound eXchange
WWW=		https://github.com/Thann/sox-noise

LICENSE=	UNLICENSE

RUN_DEPENDS=	sox:audio/sox

USES=		gnome python
USE_GNOME=	gtk30 pygobject3
USE_PYTHON=	autoplist distutils

USE_GITHUB=	yes
GH_ACCOUNT=	Thann
GH_TAGNAME=	b090771

DESKTOP_ENTRIES=	"SoX Noise" "" "audio-volume-high" "${PORTNAME}" \
			"AudioVideo;Audio;Player;" false

post-patch:
	@${REINPLACE_CMD} -e '/^version =/ \
		s,get_version(),"0.0.3.post6+g${GH_TAGNAME}",' \
		-e '/setup_requires=/,+3d' ${WRKSRC}/setup.py

.include <bsd.port.mk>
