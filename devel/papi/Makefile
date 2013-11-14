# Created by: redcrash@gmail.com
# $FreeBSD$

PORTNAME=	papi
PORTVERSION=	5.2.0
CATEGORIES=	devel
MASTER_SITES=	http://icl.cs.utk.edu/projects/papi/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	API to access the performance counter hw in the microprocessor

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	HWPMC kernel module is only available for I386 and \
			AMD64 machines
NO_PACKAGE=	Needs to be compiled for specific CPU

STRIP=		# empty
USE_LDCONFIG=	yes
USES=		gmake
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
WRKMAN=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/man
INSTALL_TARGET=	install-all

OPTIONS_DEFINE=	CORETEMP DEBUGINFO
CORETEMP_DESC=	Add Intel Core thermal sensor (need coretemp.ko)
DEBUGINFO_DESC=	Add debug information (increased verbosity)

.include <bsd.port.options.mk>

HAS_HWMPC!=	${SYSCTL} kern.hwpmc >/dev/null 2>&1 && echo yes || true

.if ${HAS_HWMPC} != "yes"
IGNORE=		needs hwmpc module loaded or compiled into the kernel. \
		Please consult hwpmc(4) on how to do it (or cat pkg-message)
.endif

CONFIGURE_ARGS+=	--with-tests=ctests

.if ${PORT_OPTIONS:MCORETEMP}
CONFIGURE_ARGS+=	--with-components=coretemp_freebsd
.endif

.if ${PORT_OPTIONS:MDEBUGINFO}
CONFIGURE_ARGS+=	--with-debug
.else
CONFIGURE_ARGS+=	--without-debug
.endif

.include <bsd.port.mk>
