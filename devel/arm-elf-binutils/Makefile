# Created by: Espen Skoglund <esk@ira.uka.de>
# $FreeBSD$

PORTNAME=	binutils
PORTVERSION=	2.34
CATEGORIES=	devel
MASTER_SITES=	SOURCEWARE/binutils/releases
PKGNAMEPREFIX=	arm-elf-

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	GNU binutils for vanilla ARM cross-development

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi

USES=		gettext gmake localbase makeinfo tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} --disable-werror \
		--disable-nls
INFO_PATH=	${PKGNAMEPREFIX:S/-$//}/info

post-install:
.for F in addr2line c++filt elfedit gprof objcopy objdump readelf size strings
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}$F  \
		${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor
	cd ${WRKSRC}/libiberty ; ${CP} libiberty.a \
		${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}/lib
	${RM} ${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info/*
	${RMDIR} ${STAGEDIR}${PREFIX}/${PKGNAMEPREFIX:S/-$//}/info

.include <bsd.port.mk>
