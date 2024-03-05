PORTNAME=	avarice
PORTVERSION=	2.14
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Atmel AVR JTAG programmer and debugging interface for avr-gdb
WWW=		https://avarice.sourceforge.net/

LICENSE=	GPLv2

USES=		compiler:c11 perl5 tar:bzip2
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ENV=	ac_cv_path_pathperl=${PERL}

.include <bsd.port.mk>
