PORTNAME=	mybee-qt
DISTVERSION=	25.02.1
CATEGORIES=	deskutils

MAINTAINER=	fbsd-ports@convectix.com
COMMENT=	GUI to interact with CBSD and MyBee appliances
WWW=		https://github.com/myb-project

LICENSE=	MIT

BUILD_DEPENDS=	curl:ftp/curl \
		cmake:devel/cmake \
		xfreerdp:net/freerdp
LIB_DEPENDS=	libvncserver.so:net/libvncserver \
		libfreerdp2.so:net/freerdp \
		libturbojpeg.so:graphics/libjpeg-turbo \
		libwinpr2.so:net/freerdp \
		libssh.so:security/libssh \
		libz-ng.so:archivers/zlib-ng
RUN_DEPENDS=	xfreerdp:net/freerdp

USES=		gl gmake qmake qt:6

USE_GITHUB=	yes
GH_ACCOUNT=	myb-project
#GH_TAGNAME=	6955032
USE_GL=		gl
USE_QT=		5compat base multimedia tools:build

PLIST_FILES=	bin/mybee-qt

OPTIONS_DEFINE=		TRACE_SYSTEMPROCESS
OPTIONS_SUB=		yes
TRACE_SYSTEMPROCESS_DESC=	Trace system process (debug)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MTRACE_SYSTEMPROCESS}
MAKE_ENV+=	TRACE_SYSTEMPROCESS=true
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/mybee-qt \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
