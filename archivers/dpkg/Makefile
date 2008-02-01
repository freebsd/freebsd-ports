# New ports collection makefile for:	dpkg
# Date created:		1 April 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	dpkg
PORTVERSION=	1.13.25
PORTREVISION=	1
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	dpkg_${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Debian package maintenance system

BUILD_DEPENDS=	po4a:${PORTSDIR}/textproc/po4a
RUN_DEPENDS=	gmd5sum:${PORTSDIR}/sysutils/coreutils \
		gpatch:${PORTSDIR}/devel/patch

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5=	yes
WRKSRC=		${WRKDIR}/dpkg-${PORTVERSION}

DPKGDIR?=	/var/db/dpkg
PLIST_SUB+=	DPKGDIR=${DPKGDIR:C,^/,,}

SUB_FILES=	pkg-install pkg-deinstall
SUB_LIST+=	DPKGDIR=${DPKGDIR}

CONFIGURE_ARGS+=--with-admindir=${DPKGDIR} --libdir=${PREFIX}/libexec \
		--program-transform-name="" --with-libintl-prefix=${LOCALBASE}

MANLANG=	"" de fr hu ja pl ru sv

MAN1_DE=	822-date.1 dpkg-architecture.1 dpkg-checkbuilddeps.1 \
		dpkg-name.1 dpkg-scanpackages.1 dpkg-scansources.1 dpkg.1
MAN5_DE=	deb-control.5 deb-old.5 deb.5 dpkg.cfg.5 dselect.cfg.5
MAN8_DE=	cleanup-info.8 dpkg-divert.8 dpkg-statoverride.8 \
		start-stop-daemon.8 update-alternatives.8

MAN1_EN=	822-date.1 dpkg-architecture.1 dpkg-buildpackage.1 \
		dpkg-checkbuilddeps.1 dpkg-deb.1 dpkg-distaddfile.1 \
		dpkg-genchanges.1 dpkg-gencontrol.1 dpkg-name.1 \
		dpkg-parsechangelog.1 dpkg-scanpackages.1 dpkg-scansources.1 \
		dpkg-shlibdeps.1 dpkg-source.1 dpkg.1 dpkg-query.1 \
		dpkg-split.1 dselect.1
MAN5_EN=	deb-control.5 deb-old.5 deb.5 dpkg.cfg.5 dselect.cfg.5
MAN8_EN=	cleanup-info.8 dpkg-divert.8 dpkg-statoverride.8 \
		install-info.8 start-stop-daemon.8 update-alternatives.8

MAN1_FR=	822-date.1 dpkg-architecture.1 dpkg-buildpackage.1 \
		dpkg-checkbuilddeps.1 dpkg-deb.1 dpkg-distaddfile.1 \
		dpkg-genchanges.1 dpkg-gencontrol.1 dpkg-name.1 \
		dpkg-parsechangelog.1 dpkg-query.1 dpkg-scanpackages.1 \
		dpkg-scansources.1 dpkg-shlibdeps.1 dpkg-source.1 dpkg-split.1 \
		dpkg.1
MAN5_FR=	deb-control.5 deb.5 dpkg.cfg.5
MAN8_FR=	cleanup-info.8 dpkg-divert.8 dpkg-statoverride.8 \
		install-info.8 start-stop-daemon.8 update-alternatives.8

MAN1_HU=	dpkg-deb.1
MAN5_HU=	deb-control.5 dpkg.cfg.5 dselect.cfg.5

MAN1_JA=	822-date.1 dpkg-checkbuilddeps.1 dpkg-deb.1 dpkg-name.1 \
		dpkg-query.1 dpkg-scanpackages.1 dpkg.1 dselect.1

MAN5_JA=	deb-control.5 deb-old.5 deb.5
MAN8_JA=	cleanup-info.8 dpkg-divert.8 dpkg-statoverride.8 \
		install-info.8 start-stop-daemon.8 update-alternatives.8

MAN1_PL=	822-date.1 dpkg-deb.1 dpkg-query.1 dpkg-split.1 dpkg.1 dselect.1
MAN5_PL=	dpkg.cfg.5 dselect.cfg.5
MAN8_PL=	dpkg-statoverride.8 start-stop-daemon.8 update-alternatives.8

MAN1_RU=	822-date.1 dpkg-checkbuilddeps.1 dpkg.1
MAN5_RU=	deb-control.5
MAN8_RU=	start-stop-daemon.8

MAN1_SV=	822-date.1 dpkg-deb.1 dpkg-query.1 dpkg-split.1 dpkg.1 dselect.1
MAN5_SV=	deb-control.5 deb-old.5 deb.5 dpkg.cfg.5 dselect.cfg.5
MAN8_SV=	start-stop-daemon.8

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${MV} ${WRKSRC}/getopt/obstack.[ch] ${WRKSRC}/lib

post-install:
	${MV} ${PREFIX}/sbin/install-info ${PREFIX}/sbin/dpkg-install-info

.for f in available diversions statoverride status
	${TOUCH} ${DPKGDIR}/${f}
.endfor

	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

.include <bsd.port.post.mk>
