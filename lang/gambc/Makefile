# New ports collection makefile for:	gambc
# Date created:        			28 December 2006
# Whom:					Rob Zinkov
#
# $FreeBSD$
#

PORTNAME=	gambc
DISTVERSION=	4.0b20
CATEGORIES=	lang
MASTER_SITES=	http://www.iro.umontreal.ca/~gambit/download/gambit/4.0/source/

MAINTAINER=	rzinkov@gmail.com
COMMENT=	Gambit programming system where the compiler generates portable C code

CONFLICTS=	ghostscript-gpl-* ghostscript-gnu-*

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--enable-single-host --enable-gcc-opts

INFO=	gambit-c

pre-configure:
	@${REINPLACE_CMD} -e 's|/4.0b20||' ${WRKSRC}/configure

post-configure:
	@${MV} ${WRKSRC}/makefile ${WRKSRC}/Makefile

.include <bsd.port.mk>
