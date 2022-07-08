PORTNAME=	xuidesigner
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4-7
DISTVERSIONSUFFIX=	-g47715db
CATEGORIES=	audio
#MASTER_SITES=	https://github.com/brummer10/XUiDesigner/releases/download/v${DISTVERSION}/
DISTNAME=	XUIDesigner_${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WYSIWYG LV2 X11UI GUI creator tool

LICENSE=	BSD0CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	xxd:editors/vim
LIB_DEPENDS=	liblilv-0.so:audio/lilv \
		libserd-0.so:devel/serd \
		libsord-0.so:devel/sord \
		libsratom-0.so:audio/sratom

USES=		gmake gnome pkgconfig python shebangfix xorg
USE_GNOME=	cairo
USE_XORG=	x11
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	brummer10
GH_PROJECT=	XUiDesigner
GH_TUPLE=	brummer10:libxputty:d7510f6:brummer10_libxputty/libxputty

SHEBANG_FILES=	tools/dsp2cc

BINARY_ALIAS=	make=${GMAKE}

post-install:
	@cd ${STAGEDIR}${PREFIX} && \
		${STRIP_CMD} \
			bin/xuidesigner \
			lib/libxputty.so.1.0

.include <bsd.port.mk>
