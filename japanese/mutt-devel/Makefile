# New ports collection makefile for:	ja-mutt
# Date created:		4 Sep 2000
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	mutt
PORTVERSION=	${VERSION}.j${JP_VERSION}.b${JP_SUBVERSION}
CATEGORIES=	japanese mail
MASTER_SITES=	http://www.ne.jp/asahi/cyber/taki/unix-mailer/mutt-dev/ \
		http://www.hiei.kit.ac.jp/~hitomi/mutt/ \
		ftp://ftp.mutt.org/pub/mutt/devel/ \
		http://www2.odn.ne.jp/~aab27060/ports/distfiles/
DISTNAME=	${PORTNAME}-${VERSION}i
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-ja${JP_VERSION}-beta${JP_SUBVERSION}${EXTRACT_SUFX} \
		manual_ja-${PRE_VERSION}i-1${EXTRACT_SUFX}

MAINTAINER=	shuna@pop16.odn.ne.jp

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang \
		giconv.2:${PORTSDIR}/converters/libiconv
.if !defined(WITH_GETTEXT)
LIB_DEPENDS+=	intl.1:${PORTSDIR}/devel/gettext
.endif
.if defined(WITH_GETTEXT)
BUILD_DEPENDS=	${LOCALBASE}/bin/msgfmt:${PORTSDIR}/devel/gettext
.endif
RUN_DEPENDS=	urlview:${PORTSDIR}/textproc/urlview

PRE_VERSION=	1.2
VERSION=	1.3.9
JP_VERSION=	0
JP_SUBVERSION=	0

DIST_SUBDIR=	mutt
NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSION}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-slang --enable-locales-fix \
		--with-iconv=${PREFIX} \
		--without-wc-funcs \
		--enable-flock --disable-fcntl \
		--sysconfdir=${PREFIX}/etc \
		--with-docdir=${PREFIX}/share/doc/mutt \
		--enable-pop --enable-imap
.if defined(WITH_GETTEXT)
CONFIGURE_ARGS+=	--with-included-gettext
.endif
MAN1=		flea.1 mutt.1 muttbug.1 mutt_dotlock.1
MAN5=		muttrc.5 mbox.5

DIFFDIR=	${WRKDIR}/${DISTNAME}-ja${JP_VERSION}-beta${JP_SUBVERSION}
DIFFNAME=	${DISTNAME}-ja${JP_VERSION}-beta${JP_SUBVERSION}.diff
DOCDIR=		${PREFIX}/share/doc/mutt

pre-patch:
	(cd ${WRKSRC}; ${PATCH} -p1 < ${DIFFDIR}/${DIFFNAME})

pre-configure:
	(cd ${WRKSRC}; aclocal -I m4)

post-install:
	${INSTALL_DATA} ${DIFFDIR}/README.JA-PATCH ${DOCDIR}
	${INSTALL_DATA} ${DIFFDIR}/manual-ja-patch.txt ${DOCDIR}
	${INSTALL_DATA} ${DIFFDIR}/sample.muttrc-tt ${DOCDIR}
	${INSTALL_DATA} ${DIFFDIR}/usage-japanese.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.txt ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.tex ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.html ${DOCDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.sgml ${DOCDIR}

.include <bsd.port.mk>
