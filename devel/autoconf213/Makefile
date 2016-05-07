# Created by: torstenb@FreeBSD.org
# $FreeBSD$

PORTNAME=	autoconf
PORTVERSION=	2.13.000227
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	LOCAL/ade/gnu
DISTNAME=	autoconf-000227
PKGNAMESUFFIX=	213

# note: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	tijl@FreeBSD.org
COMMENT=	Automatically configure source code on many Un*x platforms (legacy 2.13)

BUILD_DEPENDS=	gm4:devel/m4
RUN_DEPENDS=	gm4:devel/m4 \
		autoconf-wrapper:devel/autoconf-wrapper

BUILD_VERSION=	2.13
PLIST_SUB=	BUILD_VERSION=${BUILD_VERSION}
USES=		perl5 desthack makeinfo tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	M4=${LOCALBASE}/bin/gm4 AWK=${AWK}
CONFIGURE_ARGS=	--program-suffix=-${BUILD_VERSION}
WRKSRC=		${WRKDIR}/autoconf
INFO=		autoconf-${BUILD_VERSION}

STRIP=		# none

post-patch:
	@${RM} ${WRKSRC}/*.info* >/dev/null 2>&1 || true

post-install:
	${CHMOD} +x ${STAGEDIR}${PREFIX}/share/autoconf-${BUILD_VERSION}/config.*
	${INSTALL_SCRIPT} ${WRKSRC}/install-sh \
		${STAGEDIR}${PREFIX}/share/autoconf-${BUILD_VERSION}

.include <bsd.port.mk>
