PORTNAME=	bcc
PORTVERSION=	1995.03.12
PORTREVISION=	2
CATEGORIES=	devel lang
MASTER_SITES=	LOCAL/joerg
DISTNAME=	${PORTNAME}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Bruce's C compiler (with as and ld); can do 16-bit code

LICENSE=	GPLv2

BROKEN_aarch64=		fails to link: error adding symbols: File in wrong format
BROKEN_mips=		fails to compile: unrecognized command line option "-m32"
BROKEN_mips64=		fails to compile: unrecognized command line option "-m32"

USES=		uidfix

CONFLICTS=	dev86

.include <bsd.port.mk>
