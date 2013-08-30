# Created by: Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
# $FreeBSD$

PORTNAME=	as31
PORTVERSION=	2.0.b3
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://www.pjrc.com/tech/8051/tools/
DISTNAME=	${PORTNAME}_beta3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free 8051 assembler

# GNU make(1) allows parallel (-jX) builds to work: we plug a race in
# "bison" rule (which outputs multiple files) via order prerequisites
# (see files/patch-Makefile)
USES=		bison gmake
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		as31.1
PLIST_FILES=	bin/as31 %%X11%%bin/as31_gtk

OPTIONS_DEFINE=	X11
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_GNOME=	gtk12
.else
ALL_TARGET=	as31
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/as31 ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/as31.1 ${MANPREFIX}/man/man1
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/as31_gtk ${PREFIX}/bin
.endif

.include <bsd.port.mk>
