# New ports collection makefile for:    adom
# Version required:	0.99g14
# Date created:		22 July 1999
# Whom:			Oleg V. Volkov <rover@lglobus.ru>
#
# $FreeBSD$
#

DISTNAME=       adom-099g14-elf
PKGNAME=        adom-0.99.g14
CATEGORIES=	games
MASTER_SITES=	http://www.adom.de/adom/

MAINTAINER=	rover@lglobus.ru

RUN_DEPENDS=	/compat/linux/lib/ld-linux.so.2:${PORTSDIR}/emulators/linux_base

WRKSRC=		${WRKDIR}/adom

ONLY_FOR_ARCHS=	i386
NO_PACKAGE=     Only unmodified original package can be distributed

NO_WRKSUBDIR=   yes
STRIP=			# empty: do not touch linux binary!

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
