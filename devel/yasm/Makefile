# ex:ts=8
# Ports collection makefile for:	yasm
# Date created:			Apr 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yasm
PORTVERSION=	0.6.0
CATEGORIES=	devel lang
MASTER_SITES=	http://www.tortall.net/projects/yasm/releases/

MAINTAINER=	johnson.peter@gmail.com
COMMENT=	A complete rewrite of the NASM assembler

USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
CFLAGS:=	${CFLAGS:C/-O[0-9]//g}
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
.else
USE_GETTEXT=	yes
.endif

.if !defined(NOPORTDOCS)
INSTALL_TARGET=	install install-man
MAN1=		yasm.1
MAN7=		yasm_arch.7 yasm_dbgfmts.7 yasm_objfmts.7 yasm_parsers.7
.endif

.include <bsd.port.post.mk>
