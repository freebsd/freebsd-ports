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
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	binutils autoconf
DISTNAME=	autoconf-000227

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${LOCALBASE}/bin/gm4
CONFIGURE_ARGS=	--program-suffix=213 --datadir=${PREFIX}/share/autoconf213
WRKSRC=		${WRKDIR}/autoconf

.if defined(USE_AUTOCONF) || defined(USE_AUTOCONF_VER)
.error You have `USE_AUTOCONF' or `USE_AUTOCONF_VER' variables defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

post-patch:
	@-${RM} ${WRKSRC}/*.info*

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/install-sh \
		${PREFIX}/share/autoconf213/autoconf
	@-${RM} -fr ${PREFIX}/libexec/autoconf213
	@${MKDIR} ${PREFIX}/libexec/autoconf213
.for i in autoconf autoheader autoreconf autoscan autoupdate ifnames
	@${LN} -s ../../bin/${i}213 ${PREFIX}/libexec/autoconf213/${i}
.endfor
	@install-info ${PREFIX}/info/autoconf213.info ${PREFIX}/info/dir

.include <bsd.port.mk>
