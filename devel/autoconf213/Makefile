# New ports collection makefile for:	autoconf
# Date created:		7 October 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	autoconf
PORTVERSION=	2.13.000227
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ade/gnu
DISTNAME=	autoconf-000227

MAINTAINER=	ade@FreeBSD.org
COMMENT=	Automatically configure source code on many Un*x platforms (legacy 2.13 version)

DEPRECATED=	Please use devel/autoconf259 instead

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4
RUN_DEPENDS=	gm4:${PORTSDIR}/devel/m4

BUILD_VERSION=	213
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
LATEST_LINK=	autoconf${BUILD_VERSION}
USE_BZIP2=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CONFIG_SHELL=${SH} M4=${LOCALBASE}/bin/gm4
CONFIGURE_ARGS=	--program-suffix=${BUILD_VERSION}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
WRKSRC=		${WRKDIR}/autoconf

post-patch:
	@${RM} ${WRKSRC}/*.info* >/dev/null 2>&1 || true

post-install:
	@${CHMOD} +x ${PREFIX}/share/autoconf${BUILD_VERSION}/config.*
	@${INSTALL_SCRIPT} ${WRKSRC}/install-sh \
		${PREFIX}/share/autoconf${BUILD_VERSION}
	@-${RM} -fr ${PREFIX}/libexec/autoconf${BUILD_VERSION}
	${MKDIR} ${PREFIX}/libexec/autoconf${BUILD_VERSION}
.for i in autoconf autoheader autoreconf autoscan autoupdate ifnames
	${LN} -sf ${PREFIX}/bin/${i}${BUILD_VERSION} \
		${PREFIX}/libexec/autoconf${BUILD_VERSION}/${i}
.endfor
	install-info ${PREFIX}/info/autoconf${BUILD_VERSION}.info \
		${PREFIX}/info/dir

.include <bsd.port.mk>
