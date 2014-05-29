# Created by: Tassilo Philipp <tphilipp@potion-studios.com>
# $FreeBSD$

PORTNAME=		pspsdk
PORTVERSION=		20111215
CATEGORIES=		devel
MASTER_SITES=		http://www.potion-studios.com/
PKGNAMEPREFIX=		psptoolchain-
PKGNAMESUFFIX?=		-stage1

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain ${PORTNAME}

PSP_SDK_STAGE_PREFIX=	psp/stage1

USE_AUTOTOOLS=		libtool:env aclocal:env autoheader:env automake:env autoconf:env
HAS_CONFIGURE=		yes
USES=		gmake
CONFIGURE_ARGS?=	--prefix=${PREFIX}/${PSP_SDK_STAGE_PREFIX} \
			--with-pspdev="${LOCALBASE}/${PSP_SDK_STAGE_PREFIX}"

# First stage only needs to install some data needed to compile newlib.
# Patch a hardcoded prefix, such that we can set our own stage1 subdir.
.if ${PKGNAMESUFFIX} == "-stage1"

INSTALL_TARGET=		install-data
NO_BUILD=		yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -E 's/^(prefix="\$$pspdev")$$/#\1/' ${WRKSRC}/configure.ac
	@${REINPLACE_CMD} -E 's/^(psp_targetdir=")psp(")$$/\1.\2/' ${WRKSRC}/configure.ac

.endif

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

PLIST_SUB+=		PSP_SDK_STAGE_PREFIX=${PSP_SDK_STAGE_PREFIX}

.include <bsd.port.mk>
