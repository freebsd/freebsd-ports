# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mono
PORTVERSION=	3.2.8
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://download.mono-project.com/sources/${PORTNAME}/

MAINTAINER=	mono@FreeBSD.org
COMMENT=	An open source implementation of .NET Development Framework

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
    		bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USES=		bison gettext gmake pathfix perl5
USE_GNOME=	glib20
USE_PERL5=	build
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

# Moonlight is installed as part of www/moonlight
CONFIGURE_ARGS=	--with-moonlight=no --disable-dtrace

CONFIGURE_ENV=	ac_cv_header_sys_inotify_h=no

# Set location for .wapi creation.
MONO_SHARED_DIR=${WRKDIR}

# LC_ALL is set in order to work around issues people are having when using
# other languages.  This has shown itself in build fails and possibly other
# strange crashes.
MAKE_ENV=	MONO_SHARED_DIR="${MONO_SHARED_DIR}" \
		INSTALL_STRIP_FLAG="${STRIP}" \
		LC_ALL=C

ONLY_FOR_ARCHS=	i386 amd64 powerpc

.include <bsd.port.pre.mk>

# Base GCC used to cause problems, so compile using clang which is usualy in
# base. However, the clang version shipped with some older FreeBSD version will
# not compile Mono, in such a case, compile using a clang port.
.if ${OPSYS} == FreeBSD
.if ${OSVERSION} >= 902001 && exists(/usr/bin/clang)
CC=	/usr/bin/clang
CXX=	/usr/bin/clang++
CPP=	/usr/bin/clang-cpp
.else
BUILD_DEPENDS+=	clang33:${PORTSDIR}/lang/clang33
CC=	clang33
CXX=	clang33
CPP=	clang-cpp33
.endif
.endif

pre-everything::
	@${CAT} ${PKGMESSAGE}

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/bin/bash|#!/bin/sh|g' \
		${WRKSRC}/mcs/class/Managed.Windows.Forms/build-csproj \
		${WRKSRC}/mcs/class/Managed.Windows.Forms/build-csproj2k5 \
		${WRKSRC}/mcs/class/Mono.WebBrowser/build-csproj2k5
	@${REINPLACE_CMD} -e 's|^#!/bin/bash|#!/usr/bin/env bash|g' \
		${WRKSRC}/scripts/mono-find-provides.in \
		${WRKSRC}/scripts/mono-find-requires.in \
		${WRKSRC}/scripts/mono-test-install
	@${FIND} ${WRKSRC} -name '*.sh' | ${XARGS} ${REINPLACE_CMD} \
		-e 's|^#!/bin/bash|#!/bin/sh|g'
	@${REINPLACE_CMD} 's/(1)/(1.0)/g' ${WRKSRC}/configure

tests: build
	@${ECHO_MSG} "===> Running mono regression tests"
	@(cd ${WRKSRC}/mono/tests && ${SETENV} ${MAKE_ENV} ${GMAKE} \
		${MAKE_FLAGS} Makefile ${MAKE_ARGS} test)

post-configure:
	@${REINPLACE_CMD} -e 's|share\/man|man|g' \
		${WRKSRC}/mcs/jay/Makefile

.include "${PORTSDIR}/lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
