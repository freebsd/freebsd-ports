# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.23.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	arm-eabi-

MAINTAINER=	kientzle@gmail.com
COMMENT=	GNU binutils for vanilla ARM cross-development

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif
USE_BZIP2=	yes
USE_GMAKE=	yes
USES=		gettext
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} --enable-werror=no CFLAGS="-I${PREFIX}/include"
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info
MAN1=		${PKGNAMEPREFIX}addr2line.1 ${PKGNAMEPREFIX}as.1 \
		${PKGNAMEPREFIX}ar.1 ${PKGNAMEPREFIX}c++filt.1 \
		${PKGNAMEPREFIX}dlltool.1 ${PKGNAMEPREFIX}ld.1 \
		${PKGNAMEPREFIX}nlmconv.1 ${PKGNAMEPREFIX}nm.1 \
		${PKGNAMEPREFIX}objcopy.1 ${PKGNAMEPREFIX}objdump.1 \
		${PKGNAMEPREFIX}ranlib.1 ${PKGNAMEPREFIX}readelf.1 \
		${PKGNAMEPREFIX}size.1 ${PKGNAMEPREFIX}strings.1 \
		${PKGNAMEPREFIX}strip.1 ${PKGNAMEPREFIX}windres.1 \
		${PKGNAMEPREFIX}elfedit.1 ${PKGNAMEPREFIX}windmc.1 \
		${PKGNAMEPREFIX}gprof.1

MAKE_JOBS_SAFE=	yes

post-install:
.for F in addr2line c++filt elfedit gprof objcopy objdump readelf size strings
	${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F  \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor
	${RM} ${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info/*
	${RMDIR} ${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info

.include <bsd.port.mk>
