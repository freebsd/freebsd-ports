# New ports collection makefile for:	ja-mutt
# Version required:	1.0pre3i
# Date created:		5 Sep 1999
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#

DISTNAME=	mutt-1.0pre3i
PKGNAME=	ja-mutt-1.0b3.j0
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ftp.guug.de/pub/mutt/ \
		ftp://ftp.guug.de/pub/mutt/historic/ \
		ftp://ftp.gbnet.net/pub/mutt-international/

PATCH_SITES=	http://kondara.sdri.co.jp/~kikutani/slang/
PATCHFILES=	mutt-1.0pre3i.jp0.pat.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	shuna@pop16.odn.ne.jp

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang
BUILD_DEPENDS=	${LOCALBASE}/bin/msgfmt:${PORTSDIR}/devel/gettext \
		autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake
RUN_DEPENDS=	urlview:${PORTSDIR}/textproc/urlview

DIST_SUBDIR=	mutt
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/mutt-1.0pre3
CONFIGURE_ARGS=	--with-slang --enable-locales-fix --with-included-gettext \
		--enable-flock --disable-fcntl \
		--sysconfdir=${PREFIX}/share/mutt \
		--with-sharedir=${PREFIX}/share/mutt \
		--with-docdir=${PREFIX}/share/doc/mutt \
		--enable-pop --enable-imap

MAN1=		mutt.1 mutt_dotlock.1

pre-configure:
	(cd ${WRKSRC}; autoconf)

post-install:
	${INSTALL_DATA} ${WRKSRC}/contrib/sample.muttrc ${PREFIX}/share/doc/mutt
	${INSTALL_DATA} ${WRKSRC}/contrib/Mush.rc ${PREFIX}/share/doc/mutt
	${INSTALL_DATA} ${WRKSRC}/contrib/Pine.rc ${PREFIX}/share/doc/mutt

.include <bsd.port.mk>
