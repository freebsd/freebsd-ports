# New ports collection makefile for:	cdparanoia
# Date created:		5 Jan 2003
# Whom:			Simon 'corecode' Schubert <corecode@corecode.ath.cx>
#
# $FreeBSD$
#

PORTNAME=	cdparanoia
PORTVERSION=	3.9.8
PORTREVISION=	2
CATEGORIES=	audio sysutils
MASTER_SITES=	http://www.xiph.org/paranoia/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/^3\./III-alpha/}
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	corecode@corecode.ath.cx

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500041
LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
.endif

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		cdparanoia.1

.include <bsd.port.post.mk>
