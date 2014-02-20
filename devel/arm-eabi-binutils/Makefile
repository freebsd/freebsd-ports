# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.24
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	binutils/releases
PKGNAMEPREFIX=	arm-eabi-

MAINTAINER=	kientzle@FreeBSD.org
COMMENT=	GNU binutils for vanilla ARM cross-development

GNU_CONFIGURE=	yes
USES=		gmake

USE_BZIP2=	yes
CONFIGURE_ARGS=	--disable-nls --target=${PKGNAMEPREFIX:S/-$//} --enable-werror=no
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

post-install:
.for F in addr2line c++filt elfedit gprof objcopy objdump readelf size strings
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}$F  \
		${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor
	${RM} -f ${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info/*
	${RMDIR} ${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info

.include <bsd.port.mk>
