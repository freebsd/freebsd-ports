# New ports collection makefile for:	as31
# Date created:			Nov 21, 2003
# Whom:				Volker Stolz <stolz@i2.informatik.rwth-aachen.de>
#
# $FreeBSD$
#

PORTNAME=	as31
PORTVERSION=	2.0.b3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.pjrc.com/tech/8051/tools/
DISTNAME=	${PORTNAME}_beta3

MAINTAINER=	stolz@i2.informatik.rwth-aachen.de
COMMENT=	A free 8051 assembler

.ifndef(WITHOUT_X11)
USE_GNOME=	gtk12
PLIST_SUB+=	X11=""
.else
ALL_TARGET=	as31
PLIST_SUB+=	X11="@comment "
.endif
USE_BISON=	YES

WRKSRC=		${WRKDIR}/${PORTNAME}

do-install:
	@${INSTALL} ${WRKSRC}/as31 ${PREFIX}/bin
.ifndef(WITHOUT_X11)
	@${INSTALL} ${WRKSRC}/as31_gtk ${PREFIX}/bin
.endif

.include <bsd.port.mk>
