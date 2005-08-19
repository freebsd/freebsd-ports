# New ports collection makefile for:    gvd
# Date created:         4 Dec 2000
# Whom:                 Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=		gvd
PORTVERSION=		1.2.5
PORTREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		http://libre.act-europe.fr/gvd/
DISTNAME=		${PORTNAME}-${PORTVERSION}-src
EXTRACT_SUFX=		.tgz

MAINTAINER=		ports@FreeBSD.org
COMMENT=		GNU Visual Debugger, a graphical front-end to gdb and jdb

BUILD_DEPENDS=		adagcc:${PORTSDIR}/lang/gnat \
			tex:${PORTSDIR}/print/teTeX
LIB_DEPENDS=		gtkada.12:${PORTSDIR}/x11-toolkits/gtkada

WRKSRC=			${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CC=adagcc CFLAGS=-O
MAKE_ENV=		CC=adagcc CFLAGS=-O
USE_X_PREFIX=		yes
USE_GMAKE=		yes
USE_REINPLACE=		yes

post-patch:
	${REINPLACE_CMD} -e "s#doc/gvd#share/doc/gvd#" ${WRKSRC}/docs/Makefile.in

post-install:
	${GMAKE} -C ${WRKSRC}/docs docdir=${PREFIX}/share/doc/gvd install
	${MV} ${PREFIX}/share/doc/gvd/gvd.info ${PREFIX}/info/
	install-info ${PREFIX}/info/gvd.info ${PREFIX}/info/dir

.include <bsd.port.mk>
