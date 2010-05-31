# New ports collection makefile for:	mk-configure
# Date created:				16 September 2009
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mk-configure
PORTVERSION=	0.15.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Lightweight, easy to use replacement for GNU autotools

BUILD_DEPENDS=	bmake:${PORTSDIR}/devel/bmake
RUN_DEPENDS=	$(BUILD_DEPENDS)

.if !defined(NOPORTDOCS)
DOCFILES=	README NEWS TODO COPYRIGHT FAQ
.else
DOCFILES=
.endif

MAN1=		mkc_check_funclib.1 mkc_check_header.1 mkc_check_sizeof.1 \
		mkc_check_decl.1 mkc_check_prog.1 mkc_check_custom.1 \
		mkcmake.1
MAN7=		mk-configure.7

do-build:
	bmake -C ${WRKSRC} all

do-install:
	bmake -C ${WRKSRC} installdirs install EXTRAFILES="${DOCFILES}"

.include <bsd.port.mk>
