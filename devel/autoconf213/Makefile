# New ports collection makefile for:	autoconf
# Date created:		7 October 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

# Upgrading this port is not possible at this time because it has
# extensive implications for the entire ports system. It will be
# upgraded as soon as possible. Thanks.

PORTNAME=	autoconf213
PORTVERSION=	2.13.000227
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	binutils autoconf
DISTNAME=	autoconf-000227

MAINTAINER=	portmgr@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${PREFIX}/bin/gm4
CONFIGURE_ARGS=	--program-suffix=213 --datadir=${PREFIX}/share/autoconf213
WRKSRC=		${WRKDIR}/autoconf

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/install-sh \
		${PREFIX}/share/autoconf213/autoconf
	@install-info ${PREFIX}/info/autoconf.info ${PREFIX}/info/dir
	@install-info ${PREFIX}/info/standards.info ${PREFIX}/info/dir

.include <bsd.port.mk>
