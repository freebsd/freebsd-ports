# New ports collection makefile for:    adom
# Date created:		22 July 1999
# Whom:			Oleg V. Volkov <rover@lglobus.ru>
#
# $FreeBSD$
#

PORTNAME=	adom
PORTVERSION=	0.99.g15
CATEGORIES=	games linux
MASTER_SITES=	http://www.adom.de/adom/download/linux/
DISTNAME=	adom-099g15-elf

MAINTAINER=	rover@lglobus.ru

RUN_DEPENDS=	/compat/linux/lib/ld-linux.so.2:${PORTSDIR}/emulators/linux_base

WRKSRC=		${WRKDIR}/adom

ONLY_FOR_ARCHS=	i386
NO_CDROM=	Copy of CD must be sent to author

NO_WRKSUBDIR=	yes
STRIP=		# empty: do not strip linux binary!

do-patch:
do-configure:
do-build:
do-install:
	cd ${WRKSRC} && \
	${INSTALL_PROGRAM} adom ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${INSTALL} -d -m 755 -o ${SHAREOWN} -g ${SHAREGRP} \
	${PREFIX}/share/doc/adom
	cd ${WRKSRC} && \
	${INSTALL_MAN} readme.1st adomfaq.txt manual.doc \
	${PREFIX}/share/doc/adom
.endif

.include <bsd.port.mk>
