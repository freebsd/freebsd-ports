# Created by: Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
# $FreeBSD$

PORTNAME=	as31
PORTVERSION=	2.0.b3
PORTREVISION=	7
CATEGORIES=	devel
MASTER_SITES=	http://www.pjrc.com/tech/8051/tools/
DISTNAME=	${PORTNAME}_beta3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free 8051 assembler

LICENSE=	NONE

DEPRECATED=	unknown license
EXPIRATION_DATE=	2018-08-15

# GNU make(1) allows parallel (-jX) builds to work: we plug a race in
# "bison" rule (which outputs multiple files) via order prerequisites
# (see files/patch-Makefile)
USES=		bison gmake
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/as31 %%X11%%bin/as31_gtk man/man1/as31.1.gz

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes

X11_USE=		GNOME=gtk12
X11_ALL_TARGET_OFF=	as31

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/as31 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/as31.1 ${STAGEDIR}${MANPREFIX}/man/man1

do-install-X11-on:
	${INSTALL_PROGRAM} ${WRKSRC}/as31_gtk ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
