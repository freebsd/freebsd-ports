PORTNAME=	libsigrokdecode
PORTVERSION=	0.5.3
CATEGORIES=	devel
MASTER_SITES=	http://sigrok.org/download/source/libsigrokdecode/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Framework for hardware logic analyzers, protocol decoders library

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome libtool pathfix pkgconfig python:3.4+
USE_GNOME=	glib20

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON3=${PYTHON_CMD}
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ENV= PYTHON3="${PYTHON_CMD}"

post-patch:
	@${REINPLACE_CMD} -Ee '/python-/ s|3\.[0-9]+|${PYTHON_VER}|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
