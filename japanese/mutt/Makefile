# New ports collection makefile for:	ja-mutt
# Date created:		5 Sep 1999
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	mutt
PORTVERSION=	${VERSION}.j${JP_VERSION}
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.guug.de/pub/mutt/ \
		ftp://ftp.guug.de/pub/mutt/historic/ \
		http://www.hiei.kit.ac.jp/~hitomi/mutt/
DISTNAME=	${PORTNAME}-${VERSION}i
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		manual_ja-${VERSION:R}i-0.tar.gz

PATCH_SITES=	http://www.geocities.co.jp/SiliconValley-PaloAlto/2594/ \
		http://www2.odn.ne.jp/~aab27060/ports/distfiles/
PATCHFILES=	${DISTNAME}-jp${JP_VERSION}-diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	shuna@pop16.odn.ne.jp

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang
BUILD_DEPENDS=	${LOCALBASE}/bin/msgfmt:${PORTSDIR}/devel/gettext \
		autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake
RUN_DEPENDS=	urlview:${PORTSDIR}/textproc/urlview

VERSION=	1.2.4
JP_VERSION=	0

DIST_SUBDIR=	mutt
GNU_CONFIGURE=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSION}
ALL_TARGET=	all
CONFIGURE_ARGS=	--with-slang --enable-locales-fix --with-included-gettext \
		--enable-flock --disable-fcntl \
		--sysconfdir=${PREFIX}/etc \
		--with-docdir=${PREFIX}/share/doc/mutt \
		--enable-pop --enable-imap

MAN1=		mutt.1 mutt_dotlock.1
MAN5=		muttrc.5

pre-configure:
	(cd ${WRKSRC}; autoconf)

post-install:
	strip ${PREFIX}/bin/mutt
	strip ${PREFIX}/bin/mutt_dotlock
	strip ${PREFIX}/bin/pgpring
	${INSTALL_DATA} ${WRKDIR}/manual_ja.txt ${PREFIX}/share/doc/mutt
	${INSTALL_DATA} ${WRKDIR}/manual_ja.tex ${PREFIX}/share/doc/mutt
	${INSTALL_DATA} ${WRKDIR}/manual_ja.html ${PREFIX}/share/doc/mutt
	${INSTALL_DATA} ${WRKDIR}/manual_ja.sgml ${PREFIX}/share/doc/mutt

.include <bsd.port.mk>
