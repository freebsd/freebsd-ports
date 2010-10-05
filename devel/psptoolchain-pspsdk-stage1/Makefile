# New ports collection makefile for: psptoolchain-pspsdk-stage1
# Date created:        7 August 2009
# Whom:                Tassilo Philipp <tphilipp@potion-studios.com>
#
# $FreeBSD$
#

PORTNAME=		pspsdk
PORTVERSION=		20090127
PORTREVISION=	1
CATEGORIES=		devel
MASTER_SITES=		http://www.potion-studios.com/
PKGNAMEPREFIX=		psptoolchain-
PKGNAMESUFFIX?=		-stage1

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain ${PORTNAME}

PSP_SDK_STAGE_PREFIX=	psp/stage1

USE_AUTOTOOLS=		libtool:22:env aclocal:111:env autoheader:267:env automake:111:env autoconf:267:env
USE_GMAKE=		yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS?=	--prefix=${PREFIX}/${PSP_SDK_STAGE_PREFIX} --with-pspdev="${PREFIX}/${PSP_SDK_STAGE_PREFIX}"

# First stage only needs to install some data needed to compile newlib.
# Patch a hardcoded prefix, such that we can set our own stage1 subdir.
.if ${PKGNAMESUFFIX} == "-stage1"

INSTALL_TARGET=		install-data
NO_BUILD=		yes

post-patch:
	@${REINPLACE_CMD} -E 's/^(prefix="\$$pspdev")$$/#\1/' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -E 's/^(psp_targetdir=")psp(")$$/\1.\2/' ${WRKSRC}/configure.ac

.endif

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

PLIST_SUB+=		PSP_SDK_STAGE_PREFIX=${PSP_SDK_STAGE_PREFIX}

.include <bsd.port.mk>
