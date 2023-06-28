PORTNAME=	rtc
PORTVERSION=	2020.07.07.1
PORTREVISION=	1
CATEGORIES=	emulators linux
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kernel module which provides /dev/rtc device support

LICENSE=	BSD2CLAUSE

DEPRECATED=	Driver doesn't actually work with current FreeBSD versions
EXPIRATION_DATE=	2023-12-31

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
