PORTNAME=	cssc
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	CSSC-${PORTVERSION}

MAINTAINER=	gspurki@gmail.com
COMMENT=	Workalike for the source code control system SCCS
WWW=		https://www.gnu.org/software/cssc/

LICENSE=	GPLv3

BROKEN_mips=	fails to compile: ../gl/lib/unistd.h:135:3: "Please include config.h first."
BROKEN_mips64=	fails to compile: ../gl/lib/unistd.h:135:3: "Please include config.h first."

USES=		compiler:c11

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
INFO=		cssc

OPTIONS_DEFINE=			BINARY
OPTIONS_DEFAULT=		BINARY
BINARY_DESC=			Support binary SCCS files (Solaris interoperability)
BINARY_CONFIGURE_ENABLE=	binary

.include <bsd.port.mk>
