# New ports collection makefile for:	mingw32-gcc
# Date created:		24 October 2002
# Whom:			Lev Serebryakov <lev@serebryakov.spb.ru>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	${GCCVERSION}.${PATCHVERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	${PORTNAME}/releases/${PORTNAME}-${GCCVERSION}
PKGNAMEPREFIX=	mingw32-
DISTFILES=	${PORTNAME}-core-${GCCVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-g++-${GCCVERSION}${EXTRACT_SUFX}  \
		${PORTNAME}-objc-${GCCVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-g77-${GCCVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-ada-${GCCVERSION}${EXTRACT_SUFX}
DIST_SUBDIR=	mingw

PATCH_SITES=	${MASTER_SITE_SOURCEFORGE}
PATCH_SITE_SUBDIR=	mingw
PATCHFILES=	${PORTNAME}-${GCCVERSION}-${PATCHVERSION:S/./-/}.src.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	lev@serebryakov.spb.ru
COMMENT=	FSF gcc-3.2 for Windows cross-development

BUILD_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils \
		mingwm10.dll:${PORTSDIR}/devel/mingw32-bin-msvcrt
RUN_DEPENDS=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

GCCVERSION=	3.2
PATCHVERSION=	20020817.1

WRKSRC=		${WRKDIR}/${PORTNAME}-${GCCVERSION}

USE_BZIP2=	yes
USE_PERL5_BUILD=yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--target=${PKGNAMEPREFIX:S/-$//} \
		--enable-languages=c,c++,ada,f77,objc \
		--with-gcc --with-gnu-ld --with-gnu-as \
		--enable-threads --disable-nls \
		--disable-win32-registry --disable-shared
MAKE_ENV=	PATH=${PREFIX}/bin:${PATH}
LIBTOOLFILES=	configure gcc/configure
MAN1=		${PKGNAMEPREFIX}gcc.1 ${PKGNAMEPREFIX}g++.1 ${PKGNAMEPREFIX}g77.1  \
		cpp.1 gcov.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7

PLIST_SUB+=	PORTVERSION=${PORTVERSION} GCC_TARG=${PKGNAMEPREFIX:S/-$//} \
		GCC_REV=${GCCVERSION}

BINARIES	= gcc cpp g++ g77 gcov

# May be gcc sources was downloaded for some other port?
pre-fetch:
	for F in ${DISTFILES}; do \
		${TEST} -f ${DISTDIR}/$${F} && \
		${TEST} ! -f ${DISTDIR}/${DIST_SUBDIR}/$${F} && \
		${LN} ${DISTDIR}/$${F} ${DISTDIR}/${DIST_SUBDIR}/$${F} || \
		true ;\
	done

post-configure:
	@${PERL} -pi.bak -e 's,^(TARGET_CONFIGDIRS\s*=).+$$,\1,' ${WRKSRC}/Makefile
	@${PERL} -pi.bak -e 's,^(install-info:),\1\ndonot-\1,' ${WRKSRC}/gcc/Makefile

post-install:
.for F in ${BINARIES}
	@strip ${PREFIX}/bin/${PKGNAMEPREFIX}$F
	@${LN} -f ${PREFIX}/bin/${PKGNAMEPREFIX}$F \
		${PREFIX}/${PKGNAMEPREFIX:S/-$//}/bin/$F
.endfor

.include <bsd.port.mk>
