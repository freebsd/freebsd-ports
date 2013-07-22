# Created by: Hye-Shik Chang <perky@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dpkg
PORTVERSION=	1.16.10
PORTREVISION=	1
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	dpkg_${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Debian package maintenance system

LICENSE=	GPLv2

BUILD_DEPENDS=	po4a:${PORTSDIR}/textproc/po4a
RUN_DEPENDS=	gtar:${PORTSDIR}/archivers/gtar \
		gpatch:${PORTSDIR}/devel/patch \
		gmd5sum:${PORTSDIR}/sysutils/coreutils

USES=		gmake iconv
USE_XZ=		yes
GNU_CONFIGURE=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/dpkg-${PORTVERSION}

DPKGDIR?=	/var/db/dpkg
PLIST_SUB+=	DPKGDIR=${DPKGDIR:C,^/,,}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	DPKGDIR=${DPKGDIR}

CONFIGURE_ARGS+=--with-admindir=${DPKGDIR} --libdir=${PREFIX}/libexec \
		--program-transform-name="" --with-libintl-prefix=${LOCALBASE} \
		--disable-compiler-warnings
CONFIGURE_ENV+=	PERL_LIBDIR="${PREFIX}/${SITE_PERL_REL}"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_OFF=	--disable-nls
NLS_USES=		gettext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
MANLANG=	"" de fr hu ja pl sv
.endif

.include "Makefile.man"

post-patch:
	@${REINPLACE_CMD} 's|-t$$host|-t${ARCH}-freebsd|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} '/^#define TAR/ s|tar|g&|' \
		${WRKSRC}/lib/dpkg/dpkg.h
	@${REINPLACE_CMD} -E 's/(md5|sha1|sha256)sum/g&/g' \
		${WRKSRC}/scripts/Dpkg/Checksums.pm

post-install:
	${MV} ${PREFIX}/sbin/install-info ${PREFIX}/sbin/dpkg-install-info
.for f in available diversions statoverride status
	${TOUCH} ${DPKGDIR}/${f}
.endfor
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
