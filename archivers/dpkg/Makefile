# New ports collection makefile for:	dpkg
# Date created:		1 April 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	dpkg
PORTVERSION=	1.10.28
PORTREVISION=	1
CATEGORIES=	archivers sysutils
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/d/dpkg
DISTNAME=	dpkg_${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Package maintenance system for Debian

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5=	yes
USE_AUTOTOOLS=	autoconf:259
WRKSRC=		${WRKDIR}/dpkg-${PORTVERSION}

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-admindir=${PREFIX}/var/dpkg
MAKE_ENV=	GETTEXTBASE=${LOCALBASE}

MAN1=		822-date.1 dpkg-architecture.1 dpkg-buildpackage.1 \
		dpkg-checkbuilddeps.1 dpkg-deb.1 dpkg-distaddfile.1 \
		dpkg-genchanges.1 dpkg-gencontrol.1 dpkg-name.1 \
		dpkg-parsechangelog.1 dpkg-scanpackages.1 dpkg-scansources.1 \
		dpkg-shlibdeps.1 dpkg-source.1 md5sum.1
MAN5=		deb-control.5 deb-old.5 deb.5 dpkg.cfg.5 dselect.cfg.5
MAN8=		cleanup-info.8 dpkg-divert.8 dpkg-query.8 dpkg-split.8 \
		dpkg-statoverride.8 dpkg.8 dselect.8 install-info.8 \
		start-stop-daemon.8 update-alternatives.8

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's,^\(ALL_LINGUAS.*\)tl \(.*\)$$,\1\2,g' \
		${WRKSRC}/configure.in

post-install:
	${MV} ${PREFIX}/sbin/install-info ${PREFIX}/sbin/dpkg-install-info

.include <bsd.port.mk>
