# ex:ts=8
# New ports collection makefile for:	trio
# Date created:			Jun 3, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	trio
PORTVERSION=	1.3
CATEGORIES=	devel
MASTER_SITES=	http://www.contactor.se/~dast/stuff/

MAINTAINER=	ijliao@FreeBSD.org

MANCOMPRESSED=	no
MAN3=	trio_printf.3 trio_scanf.3 trio_register.3 strio.3

post-patch:
	@${PERL} -pi -e "s,^CFLAGS,#CFLAGS,g" ${WRKSRC}/Makefile

do-install:
.for file in trio.h triop.h
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include
.endfor
	${INSTALL_DATA} ${WRKSRC}/libtrio.a ${PREFIX}/lib
.for file in ${MAN3}
	${INSTALL_MAN} ${WRKSRC}/man/man3/${file} ${MANPREFIX}/man/man3
.endfor

.include <bsd.port.mk>
