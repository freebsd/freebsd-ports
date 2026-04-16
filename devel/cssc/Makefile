PORTNAME=	cssc
DISTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GNU
DISTNAME=	CSSC-${DISTVERSION}

MAINTAINER=	alven@FreeBSD.org
COMMENT=	GNU Project\'s replacement for the source code control system SCCS
WWW=		https://www.gnu.org/software/cssc/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes

INFO=		cssc

OPTIONS_DEFINE=			BINARY
OPTIONS_DEFAULT=		BINARY

BINARY_DESC=			Support binary SCCS files (Solaris interoperability)

BINARY_CONFIGURE_ENABLE=	binary

.include <bsd.port.mk>
