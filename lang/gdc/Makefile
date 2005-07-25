# New ports collection makefile for:	D Front End for GCC
# Date created:		18 November 2004
# Whom:			Masanori OZAWA (ozawa@ongs.co.jp)
#
# $FreeBSD$
#

PORTNAME=	gdc
PORTVERSION=	0.15
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC} \
		http://home.earthlink.net/~dvdfrdmn/d/:gdc
MASTER_SITE_SUBDIR=	snapshots/${__GCC_VERSIONSTRING}
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2:gdc \
		gcc-core-${__GCC_VERSIONSTRING}.tar.bz2 \
		gcc-g++-${__GCC_VERSIONSTRING}.tar.bz2
EXTRACT_ONLY=	gcc-core-${__GCC_VERSIONSTRING}.tar.bz2 \
		gcc-g++-${__GCC_VERSIONSTRING}.tar.bz2

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	D Front End for GCC

ONLY_FOR_ARCHS=	i386 alpha

USE_BISON=	yes
USE_BZIP2=	yes
USE_GCC=	3.4
USE_GMAKE=	yes
USE_REINPLACE=	yes

__GCC_VERSION=	3.4.5
__GCC_REVISION=	20050719
__GCC_VERSIONSTRING=	3.4-${__GCC_REVISION}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	It is supported on FreeBSD 5.x and later.
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

GXX_INC=${PREFIX}/lib/gcc/${CONFIGURE_TARGET}/${__GCC_VERSION}/include/c++/
GDC_INC=${PREFIX}/include/d/${__GCC_VERSION}
CONFIGURE_ARGS+=--disable-nls --with-system-zlib \
		--with-libiconv-prefix=${LOCALBASE} \
		--with-gxx-include-dir=${GXX_INC} \
		--disable-shared --prefix=${PREFIX} \
		--enable-languages=c,c++,d
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
GNU_CONFIGURE=	yes
PLIST_SUB=	__GCC_VER=${__GCC_VERSION} CONF_TARGET=${CONFIGURE_TARGET}

.if defined(_GCC_BUILD_DEPENDS)
RUN_DEPENDS+=	${_GCC_BUILD_DEPENDS}:${PORTSDIR}/lang/${_GCC_BUILD_DEPENDS}
SUFFIX=		34
CONFIGURE_ARGS+=	--program-suffix=${SUFFIX}
.endif

WRKSRC=		${WRKDIR}/gcc-${__GCC_VERSIONSTRING}
GCCDIR=		${WRKSRC}/gcc

pre-fetch:
.ifdef 	WITH_UNITTEST
	@echo ""
	@echo "Warning:"
	@echo "         WITH_UNITTEST enabled."
	@echo "         On FreeBSD, some unit tests will fail."
	@echo ""
	@sleep 5
.endif

post-extract:
	@${TAR} xjf ${DISTDIR}/${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		-C ${GCCDIR}

post-patch:
	@cd ${WRKSRC} && ${SH} ./gcc/d/setup-gcc.sh
	@${REINPLACE_CMD} -e \
		's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
		${GCCDIR}/version.c
	@${REINPLACE_CMD} -e \
		'/^gcc_d_include_dir/s|^.*$$|gcc_d_include_dir = ${GDC_INC}|' \
		${GCCDIR}/d/Make-lang.in

post-build:
.ifdef 	WITH_UNITTEST
	@cd ${WRKSRC} && ${GMAKE} check-target-libphobos
.endif

do-install:
	${INSTALL_PROGRAM} -o root -g wheel -m 755 ${GCCDIR}/gdc ${PREFIX}/bin/
	@${STRIP_CMD} ${PREFIX}/bin/gdc
	${INSTALL_PROGRAM} -o root -g wheel -m 755 ${GCCDIR}/cc1d ${PREFIX}/bin/
	@${STRIP_CMD} ${PREFIX}/bin/cc1d
	@cd ${WRKSRC} && ${GMAKE} install-target-libphobos

.include <bsd.port.post.mk>
