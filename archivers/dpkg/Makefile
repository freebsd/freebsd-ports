# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dpkg
PORTVERSION=	1.18.18
CATEGORIES=	archivers sysutils
MASTER_SITES=	DEBIAN_POOL
DISTNAME=	dpkg_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Debian package maintenance system

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	po4a:textproc/po4a
RUN_DEPENDS=	gtar:archivers/gtar \
		gpatch:devel/patch

GNU_CONFIGURE=	yes
USES=		cpe gmake iconv libtool ncurses perl5 pkgconfig tar:xz
CPE_VENDOR=	debian
WRKSRC=		${WRKDIR}/dpkg-${PORTVERSION}

DPKGDIR?=	/var/db/dpkg
PLIST_SUB=	DPKGDIR=${DPKGDIR}

CONFIGURE_ARGS=	--with-admindir=${DPKGDIR} \
		--libdir=${PREFIX}/libexec \
		--with-libintl-prefix=${LOCALBASE} \
		--with-logdir=/var/log \
		--with-libmd
CONFIGURE_ENV=	PERL_LIBDIR="${PREFIX}/${SITE_PERL_REL}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-install:
	(cd ${STAGEDIR}${DPKGDIR} && ${TOUCH} available.sample \
		diversions.sample statoverride.sample status.sample)

.include <bsd.port.mk>
