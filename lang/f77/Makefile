# Ports collection makefile for:	f77-freebsd
# Date created:				19 JAN 1999
# Whom:					Steven G. Kargl
#
# $FreeBSD$
#

PORTNAME=	f77
PORTVERSION=	0.3
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	lioux
DISTNAME=	f77-freebsd.0.3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fortran 77 driver utility for f2c and gcc

.ifdef GNU_CPP
RUN_DEPENDS=	${PREFIX}/bin/f2c:${PORTSDIR}/lang/f2c
.else
RUN_DEPENDS=	${PREFIX}/bin/fpp:${PORTSDIR}/devel/fpp \
		${PREFIX}/bin/f2c:${PORTSDIR}/lang/f2c
.endif

# Set F77NAME to the name of the Fortran 77 wrapper.
F77NAME=	ftn77

.ifdef GNU_CPP
MAKE_ARGS=	"CFLAGS= ${CFLAGS} -DPP_COMMAND='\"/usr/bin/cpp\"' \
		-DF2C_COMMAND='\"${PREFIX}/bin/f2c\"'"
.else
MAKE_ARGS=	"CFLAGS= ${CFLAGS} -DSUN_FPP \
		-DPP_COMMAND='\"${PREFIX}/bin/fpp\"' \
		-DF2C_COMMAND='\"${PREFIX}/bin/f2c\"'"
.endif

ALL_TARGET=	depend all
MAN1=		${F77NAME}.1
PLIST=		${WRKDIR}/PLIST

pre-install:
	@${ECHO_CMD} 'bin/${F77NAME}' > ${PLIST}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/f77 ${PREFIX}/bin/${F77NAME}
	@${SED} -e 's/F77/${F77NAME}/g' -e 's/f77/${F77NAME}/g' \
	${WRKSRC}/f77.1  > ${WRKSRC}/${F77NAME}.1
	${INSTALL_MAN} ${WRKSRC}/${F77NAME}.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
