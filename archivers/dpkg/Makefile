# New ports collection makefile for:	dpkg
# Date created:		1 April 2003
# Whom:			Hye-Shik Chang <perky@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	dpkg
PORTVERSION=	1.9.21
PORTREVISION=	1
CATEGORIES=	archivers sysutils
MASTER_SITES=	http://ftp.debian.org/debian/pool/main/d/dpkg/
DISTNAME=	dpkg_${PORTVERSION}

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Package maintenance system for Debian

LIB_DEPENDS=	intl.5:${PORTSDIR}/devel/gettext-old \
		iconv.3:${PORTSDIR}/converters/libiconv

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_AUTOCONF=	213
WRKSRC=		${WRKDIR}/dpkg-${PORTVERSION}

CONFIGURE_ARGS=	--with-libiconv-prefix=${LOCALBASE} \
		--with-admindir=${PREFIX}/var/dpkg
MAKE_ENV=	GETTEXTBASE=${LOCALBASE}

MAN1=		822-date.1 dpkg-architecture.1 dpkg-buildpackage.1 \
		dpkg-checkbuilddeps.1 dpkg-deb.1 dpkg-distaddfile.1 \
		dpkg-genchanges.1 dpkg-gencontrol.1 dpkg-name.1 \
		dpkg-parsechangelog.1 dpkg-shlibdeps.1 dpkg-source.1 \
		md5sum.1
MAN8=		cleanup-info.8 dpkg-divert.8 dpkg-scanpackages.8 \
		dpkg-scansources.8 dpkg-split.8 dpkg-statoverride.8 \
		dpkg.8 dselect.8 install-info.8 start-stop-daemon.8 \
		update-alternatives.8 update-rc.d.8

.include <bsd.port.mk>
