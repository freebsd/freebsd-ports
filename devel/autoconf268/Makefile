# New ports collection makefile for:	autoconf
# Date created:		7 October 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	autoconf
PORTVERSION=	2.52
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	autoconf

MAINTAINER=	portmgr@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${LOCALBASE}/bin/gm4

MAN1=		autoconf.1 autoheader.1 autoreconf.1 \
		autoscan.1 autoupdate.1 config.guess.1 \
		config.sub.1 ifnames.1

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/config/install-sh ${PREFIX}/share/autoconf

.include <bsd.port.mk>
