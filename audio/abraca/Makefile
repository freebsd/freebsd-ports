# Created by: Olivier Smedts <olivier@gid0.org>
# $FreeBSD$

PORTNAME=	abraca
PORTVERSION=	0.8.2
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	GTK2 client for the XMMS2 music player

BUILD_DEPENDS=	${LOCALBASE}/bin/valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libxmmsclient.so:${PORTSDIR}/audio/xmms2 \
		libgee-0.8.so:${PORTSDIR}/devel/libgee
RUN_DEPENDS=	gnome-themes-standard>=3.0.0:${PORTSDIR}/x11-themes/gnome-themes-standard \
		gnome-icon-theme>=0:${PORTSDIR}/misc/gnome-icon-theme

USES=		pkgconfig python:build tar:bzip2
USE_GNOME=	gtk30

MAKE_ARGS=	MANDIR=${MANPREFIX}/man

OPTIONS_DEFINE=	NLS
OPTIONS_DEFAULT=	NLS

OPTIONS_SUB=	yes
NLS_USES=	gettext

.include <bsd.port.options.mk>

post-patch:
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/\.load(/s/ intltool//' \
		-e '/recurse/s/ po//' ${WRKSRC}/wscript
.endif

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} waf configure ${_MAKE_JOBS} \
		--prefix=${PREFIX} --mandir=${PREFIX}/man

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} waf build ${_MAKE_JOBS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} waf install --destdir=${STAGEDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
