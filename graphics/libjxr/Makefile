# $FreeBSD$

PORTNAME=	jxrlib
PORTVERSION=	1.1
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=pool/main/j/jxrlib
DISTFILES=	jxrlib_${PORTVERSION}.orig.tar.gz	\
		jxrlib_${PORTVERSION}-6.debian.tar.xz

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	Library for JPEG XR, a.k.a. Windows MediaTM Photo

LICENSE=	BSD

USES=		dos2unix uidfix
USE_LDCONFIG=	yes
MAKEFILE=	BSDmakefile	# created by do-configure
MAKE_ENV=	WRKDIR="${WRKDIR}"

do-configure:
	${RM} -f ${WRKSRC}/BSDmakefile
.for d in libjpegxr jxrgluelib JxrEncApp JxrDecApp
	${MKDIR} ${WRKSRC}/$d
	${LN} -sf ${FILESDIR}/BSDmakefile.$d ${WRKSRC}/$d/BSDmakefile
	${ECHO} "SUBDIR+=$d" >> ${WRKSRC}/BSDmakefile
.endfor
	${ECHO} '.include <bsd.subdir.mk>' >> ${WRKSRC}/BSDmakefile

post-build:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/jxrlib

regression-test test check: build
	${SETENV} WRKSRC="${WRKSRC}" ${SH} -x ${FILESDIR}/test.sh

.include <bsd.port.mk>
