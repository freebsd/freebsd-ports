# New ports collection makefile for:	distcc
# Date created:				25 June 2002
# Whom:					Frerich Raabe <frerich.raabe@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	distcc
PORTVERSION=	0.4
CATEGORIES=	devel
MASTER_SITES=	http://ftp.samba.org/ftp/distcc/

MAINTAINER=	frerich.raabe@gmx.de

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include ${CPPFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${LDFLAGS}"

BUILD_WRKSRC=	${WRKSRC}/src

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/distcc ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/src/distccd ${PREFIX}/sbin

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
