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
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE} ${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	binutils autoconf
DISTNAME=	autoconf-000227

MAINTAINER=	alane@FreeBSD.org

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CONFIG_SHELL=/bin/sh
CONFIGURE_ENV+=	M4=${LOCALBASE}/bin/gm4
CONFIGURE_ARGS=	--program-suffix=213
WRKSRC=		${WRKDIR}/autoconf

.if defined(USE_AUTOCONF) || defined(USE_AUTOCONF_VER)
pre-everything:
	@${ECHO} ===========================================================
	@${ECHO} "You have 'USE_AUTOCONF' or 'USE_AUTOCONF_VER' variables"
	@${ECHO} "defined either in environment or in make(1) arguments."
	@${ECHO} "Please undefine them and try again."
	@${ECHO} ===========================================================
	@${FALSE}
.endif # defined(USE_AUTOCONF) || defined(USE_AUTOCONF_VER)

post-patch:
	@${RM} ${WRKSRC}/*.info* >/dev/null 2>&1 || true

post-install:
	@${CHMOD} +x ${PREFIX}/share/autoconf213/config.*
	@${INSTALL_SCRIPT} ${WRKSRC}/install-sh \
		${PREFIX}/share/autoconf213
	@-${RM} -fr ${PREFIX}/libexec/autoconf213
	${MKDIR} ${PREFIX}/libexec/autoconf213
.for i in autoconf autoheader autoreconf autoscan autoupdate ifnames
	${LN} -sf ${PREFIX}/bin/${i}213 \
		${PREFIX}/libexec/autoconf213/${i}
.endfor
	install-info ${PREFIX}/info/autoconf213.info \
		${PREFIX}/info/dir

.include <bsd.port.mk>
