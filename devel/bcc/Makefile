PORTNAME=	bcc
PORTVERSION=	1995.03.12
PORTREVISION=	3
CATEGORIES=	devel lang
MASTER_SITES=	LOCAL/joerg
DISTNAME=	${PORTNAME}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Bruce's C compiler (with as and ld); can do 16-bit code

LICENSE=	GPLv2

BROKEN_aarch64=		fails to link: error adding symbols: File in wrong format

USES=		uidfix

CONFLICTS=	dev86

.include <bsd.port.mk>
