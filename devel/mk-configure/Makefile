# New ports collection makefile for:	mk-configure
# Date created:				16 September 2009
# Whom:					Mikolaj Golub <to.my.trociny@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	mk-configure
PORTVERSION=	0.11.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	to.my.trociny@gmail.com
COMMENT=	Lightweight, easy to use replacement for GNU autotools

BUILD_DEPENDS=	${LOCALBASE}/share/mk/bsd.sys.mk:${PORTSDIR}/devel/netbsd-pkgsrc-mk-files
RUN_DEPENDS=	${LOCALBASE}/share/mk/bsd.sys.mk:${PORTSDIR}/devel/netbsd-pkgsrc-mk-files

.if !defined(NOPORTDOCS)
DOCFILES=	README NEWS TODO COPYRIGHT FAQ
.else
DOCFILES=
.endif

MAN1=		mkc_check_funclib.1 mkc_check_header.1 mkc_check_sizeof.1 \
		mkc_check_decl.1 mkc_check_prog.1
MAN7=		mk-configure.7

do-build:
	bmake -C ${WRKSRC} all MKFILESDIR=${LOCALBASE}/share/mk

do-install:
	bmake -C ${WRKSRC} install-dirs install EXTRAFILES="${DOCFILES}"

.include <bsd.port.mk>
