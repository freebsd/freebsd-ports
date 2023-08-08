PORTNAME=	tcl-signal
PORTVERSION=	1.4.5
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Dynamically loadable signal handling for Tcl/Tk scripts
WWW=		https://www.nyx.net/~mschwart/signal_ext.html

LICENSE=	MIT

USES+=		tcl:tea autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	wjoye
GH_PROJECT=	tclsignal

PLIST_FILES=	lib/tclsignalConfig.sh \
		lib/tclsignal${PORTVERSION}/libtclsignal${PORTVERSION}.so \
		lib/tclsignal${PORTVERSION}/pkgIndex.tcl

post-patch:
	${REINPLACE_CMD} -e 's|1\.4\.4\.1|${PORTVERSION}|' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
