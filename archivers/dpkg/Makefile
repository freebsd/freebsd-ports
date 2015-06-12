# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dpkg
PORTVERSION=	1.18.1
CATEGORIES=	archivers sysutils
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	dpkg_${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Debian package maintenance system

LICENSE=	GPLv2

BUILD_DEPENDS=	po4a:${PORTSDIR}/textproc/po4a
RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar \
		gpatch:${PORTSDIR}/devel/patch

GNU_CONFIGURE=	yes
USES=		cpe gmake iconv libtool perl5 pkgconfig tar:xz
CPE_VENDOR=	debian
WRKSRC=		${WRKDIR}/dpkg-${PORTVERSION}

DPKGDIR?=	/var/db/dpkg
PLIST_SUB+=	DPKGDIR=${DPKGDIR}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	DPKGDIR=${DPKGDIR}

CONFIGURE_ARGS+=--with-admindir=${DPKGDIR} --libdir=${PREFIX}/libexec \
		--with-libintl-prefix=${LOCALBASE} \
		--with-logdir=/var/log
CONFIGURE_ENV+=	PERL_LIBDIR="${PREFIX}/${SITE_PERL_REL}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-install:
	(cd ${STAGEDIR}${DPKGDIR} && ${MKDIR} available diversions \
		statoverride status)

.include <bsd.port.mk>
