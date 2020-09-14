# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rtc
PORTVERSION=	2020.07.07.1
CATEGORIES=	emulators linux
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	jamie@catflap.org
COMMENT=	Kernel module which provides /dev/rtc device support

LICENSE=	BSD2CLAUSE

USES=		kmod uidfix

WRKSRC=		${WRKDIR}/files

MAKE_ARGS=	KMODDIR="${KMODDIR}"

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${FILESDIR} && ${CP} Makefile *.[ch] ${WRKSRC}/

post-install:
	${INSTALL_DATA} ${WRKSRC}/rtc.h ${STAGEDIR}${PREFIX}/include
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/test.c ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
