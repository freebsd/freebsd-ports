# Created by: joerg
# $FreeBSD$

PORTNAME=	bcc
PORTVERSION=	1995.03.12
PORTREVISION=	1
CATEGORIES=	devel lang
DISTNAME=	${PORTNAME}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Bruce's C compiler (with as and ld); can do 16-bit code

BROKEN=		unfetchable (MASTER_SITES not defined)

USES=		uidfix

CONFLICTS=	bin86-[0-9]* dev86-[0-9]*

BROKEN_aarch64=		Fails to link: error adding symbols: File in wrong format

.include <bsd.port.mk>
