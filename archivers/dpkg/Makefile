# New ports collection makefile for:	dpkg
# Date created:		1 April 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	dpkg
PORTVERSION=	1.14.25
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	dpkg_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
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
CONFIGURE_ENV+=	PERL_LIBDIR="${PREFIX}/${SITE_PERL_REL}"

MANLANG=	"" de fr hu ja pl sv

MAN1_EN=	822-date.1 \
		dpkg-architecture.1 \
		dpkg-buildpackage.1 \
		dpkg-checkbuilddeps.1 \
		dpkg-deb.1 \
		dpkg-distaddfile.1 \
		dpkg-genchanges.1 \
		dpkg-gencontrol.1 \
		dpkg-gensymbols.1 \
		dpkg-name.1 \
		dpkg-parsechangelog.1 \
		dpkg-query.1 \
		dpkg-scanpackages.1 \
		dpkg-scansources.1 \
		dpkg-shlibdeps.1 \
		dpkg-source.1 \
		dpkg-split.1 \
		dpkg-trigger.1 \
		dpkg.1 \
		dselect.1
MAN5_EN=	deb-control.5 \
		deb-old.5 \
		deb-override.5 \
		deb-shlibs.5 \
		deb-substvars.5 \
		deb-symbols.5 \
		deb-triggers.5 \
		deb-version.5 \
		deb.5 \
		dpkg.cfg.5 \
		dselect.cfg.5
MAN8_EN=	cleanup-info.8 \
		dpkg-divert.8 \
		dpkg-statoverride.8 \
		install-info.8 \
		start-stop-daemon.8 \
		update-alternatives.8

MAN1_DE=	822-date.1 \
		dpkg-architecture.1 \
		dpkg-buildpackage.1 \
		dpkg-checkbuilddeps.1 \
		dpkg-deb.1 \
		dpkg-distaddfile.1 \
		dpkg-genchanges.1 \
		dpkg-gencontrol.1 \
		dpkg-name.1 \
		dpkg-parsechangelog.1 \
		dpkg-query.1 \
		dpkg-scanpackages.1 \
		dpkg-scansources.1 \
		dpkg-shlibdeps.1 \
		dpkg-source.1 \
		dpkg-split.1 \
		dpkg-trigger.1 \
		dpkg.1 \
		dselect.1
MAN5_DE=	deb-control.5 \
		deb-old.5 \
		deb-override.5 \
		deb-shlibs.5 \
		deb-substvars.5 \
		deb-symbols.5 \
		deb-triggers.5 \
		deb-version.5 \
		deb.5 \
		dpkg.cfg.5 \
		dselect.cfg.5
MAN8_DE=	cleanup-info.8 \
		dpkg-divert.8 \
		dpkg-statoverride.8 \
		install-info.8 \
		start-stop-daemon.8 \
		update-alternatives.8

MAN1_FR=	822-date.1 \
		dpkg-architecture.1 \
		dpkg-buildpackage.1 \
		dpkg-checkbuilddeps.1 \
		dpkg-deb.1 \
		dpkg-distaddfile.1 \
		dpkg-genchanges.1 \
		dpkg-gencontrol.1 \
		dpkg-name.1 \
		dpkg-parsechangelog.1 \
		dpkg-query.1 \
		dpkg-scanpackages.1 \
		dpkg-scansources.1 \
		dpkg-shlibdeps.1 \
		dpkg-source.1 \
		dpkg-split.1 \
		dpkg-trigger.1 \
		dpkg.1 \
		dselect.1
MAN5_FR=	deb-control.5 \
		deb-old.5 \
		deb-override.5 \
		deb-shlibs.5 \
		deb-substvars.5 \
		deb-symbols.5 \
		deb-triggers.5 \
		deb-version.5 \
		deb.5 \
		dpkg.cfg.5 \
		dselect.cfg.5
MAN8_FR=	cleanup-info.8 \
		dpkg-divert.8 \
		dpkg-statoverride.8 \
		install-info.8 \
		start-stop-daemon.8 \
		update-alternatives.8

MAN5_HU=	dpkg.cfg.5 \
		dselect.cfg.5

MAN1_JA=	dselect.1
MAN5_JA=	deb-old.5 \
		deb.5
MAN8_JA=	update-alternatives.8

MAN1_PL=	822-date.1 \
		dpkg-architecture.1 \
		dpkg-buildpackage.1 \
		dpkg-checkbuilddeps.1 \
		dpkg-deb.1 \
		dpkg-distaddfile.1 \
		dpkg-genchanges.1 \
		dpkg-gencontrol.1 \
		dpkg-name.1 \
		dpkg-parsechangelog.1 \
		dpkg-query.1 \
		dpkg-scanpackages.1 \
		dpkg-scansources.1 \
		dpkg-shlibdeps.1 \
		dpkg-source.1 \
		dpkg-split.1 \
		dpkg-trigger.1 \
		dpkg.1 \
		dselect.1
MAN5_PL=	deb-control.5 \
		deb-old.5 \
		deb-override.5 \
		deb-shlibs.5 \
		deb-substvars.5 \
		deb-symbols.5 \
		deb-triggers.5 \
		deb-version.5 \
		deb.5 \
		dpkg.cfg.5 \
		dselect.cfg.5
MAN8_PL=	cleanup-info.8 \
		dpkg-divert.8 \
		dpkg-statoverride.8 \
		install-info.8 \
		start-stop-daemon.8 \
		update-alternatives.8

MAN1_SV=	822-date.1 \
		dpkg-architecture.1 \
		dpkg-buildpackage.1 \
		dpkg-checkbuilddeps.1 \
		dpkg-deb.1 \
		dpkg-distaddfile.1 \
		dpkg-genchanges.1 \
		dpkg-gencontrol.1 \
		dpkg-name.1 \
		dpkg-parsechangelog.1 \
		dpkg-query.1 \
		dpkg-scanpackages.1 \
		dpkg-scansources.1 \
		dpkg-shlibdeps.1 \
		dpkg-source.1 \
		dpkg-split.1 \
		dpkg-trigger.1 \
		dpkg.1 \
		dselect.1
MAN5_SV=	deb-control.5 \
		deb-old.5 \
		deb-override.5 \
		deb-shlibs.5 \
		deb-substvars.5 \
		deb-symbols.5 \
		deb-triggers.5 \
		deb-version.5 \
		deb.5 \
		dpkg.cfg.5 \
		dselect.cfg.5
MAN8_SV=	cleanup-info.8 \
		dpkg-divert.8 \
		dpkg-statoverride.8 \
		install-info.8 \
		start-stop-daemon.8 \
		update-alternatives.8

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|ncursesw/||g' \
		${WRKSRC}/dselect/Makefile.in \
		${WRKSRC}/dselect/dselect.h \
		${WRKSRC}/dselect/main.cc \
		${WRKSRC}/src/Makefile.in

post-install:
	${MV} ${PREFIX}/sbin/install-info ${PREFIX}/sbin/dpkg-install-info
.for f in available diversions statoverride status
	${TOUCH} ${DPKGDIR}/${f}
.endfor
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
