# New ports collection makefile for:	binutils
# Date created:		9 July 2009
# Whom:			Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	binutils
PORTVERSION=	2.19.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases

MAINTAINER=	mm@FreeBSD.org
COMMENT=	GNU binary tools

USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

BUILD_DEPENDS=	${LOCALBASE}/lib/libgmp.so:${PORTSDIR}/math/libgmp4 \
		${LOCALBASE}/lib/libmpfr.so:${PORTSDIR}/math/mpfr

CFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--with-system-zlib \
			--with-gmp=${LOCALBASE} \
			--with-mpfr=${LOCALBASE}

MAN1=		addr2line.1 \
		ar.1 \
		as.1 \
		c++filt.1 \
		gprof.1 \
		dlltool.1 \
		ld.1 \
		nlmconv.1 \
		nm.1 \
		objcopy.1 \
		objdump.1 \
		ranlib.1 \
		readelf.1 \
		size.1 \
		strings.1 \
		strip.1 \
		windmc.1 \
		windres.1

INFO=		as \
		binutils \
		standards \
		gprof \
		bfd \
		configure \
		ld

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment"
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
PLIST_SUB+=	POST7="@comment " PRE7=""
.else
PLIST_SUB+=	POST7="" PRE7="@comment "
.endif

.if ${ARCH} == "amd64"
ARCH=		x86_64
.endif

post-install:
	@${FIND} -ds ${PREFIX}/${CONFIGURE_TARGET} ! -type d | \
		${SED} -e 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} -ds ${PREFIX}/${CONFIGURE_TARGET} -type d | \
		${SED} -e 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
