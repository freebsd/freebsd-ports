# New ports collection makefile for:	dpkg
# Date created:		1 April 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	dpkg
PORTVERSION=	1.15.8.12
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	dpkg_${PORTVERSION}

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	Debian package maintenance system

LICENSE=	GPLv2

BUILD_DEPENDS=	po4a:${PORTSDIR}/textproc/po4a
RUN_DEPENDS=	gmd5sum:${PORTSDIR}/sysutils/coreutils \
		gpatch:${PORTSDIR}/devel/patch

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5=	yes
MAKE_JOBS_SAFE=	yes
WRKSRC=		${WRKDIR}/dpkg-${PORTVERSION}

DPKGDIR?=	/var/db/dpkg
PLIST_SUB+=	DPKGDIR=${DPKGDIR:C,^/,,}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	DPKGDIR=${DPKGDIR}

CONFIGURE_ARGS+=--with-admindir=${DPKGDIR} --libdir=${PREFIX}/libexec \
		--program-transform-name="" --with-libintl-prefix=${LOCALBASE} \
		--disable-compiler-warnings
CONFIGURE_ENV+=	PERL_LIBDIR="${PREFIX}/${SITE_PERL_REL}"

.if !defined(WITHOUT_NLS)
MANLANG=	"" de fr hu ja pl sv
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include "Makefile.man"

post-patch:
	@${REINPLACE_CMD} -e 's|ncursesw/||g' ${WRKSRC}/dselect/main.cc

post-install:
	${MV} ${PREFIX}/sbin/install-info ${PREFIX}/sbin/dpkg-install-info
.for f in available diversions statoverride status
	${TOUCH} ${DPKGDIR}/${f}
.endfor
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
