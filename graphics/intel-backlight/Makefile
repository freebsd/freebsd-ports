# Created by: Michael Gmelin <freebsd@grem.de>
# $FreeBSD$

PORTNAME=		intel-backlight
DISTVERSION=		20180303
CATEGORIES=		graphics

MAINTAINER=		jmd@freebsd.org
COMMENT=		Control backlight on various modern Intel(R) GPUs

LICENSE=		MIT
LICENSE_FILE=		${WRKSRC}/COPYING

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	This hardware is only found on Intel x86 systems

LIB_DEPENDS=		libdrm.so:graphics/libdrm \
			libpciaccess.so:devel/libpciaccess

USE_GITHUB=		yes
GH_ACCOUNT=		FreeBSDDesktop
GH_PROJECT=		intel_backlight_fbsd
GH_TAGNAME=		7339989

PORTEXAMPLES=		asmc_backlight.sh \
			isl_backlight.sh

INSTALL_TARGET=		install-strip

OPTIONS_SUB=		yes
OPTIONS_DEFINE=		EXAMPLES SUID
OPTIONS_DEFAULT=	SUID
SUID_DESC=		Install intel_backlight with the setuid bit set

do-install-EXAMPLES-on:
	cd ${WRKSRC} &&	${COPYTREE_SHARE} "${PORTEXAMPLES}" ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.options.mk>
.include <bsd.port.mk>
