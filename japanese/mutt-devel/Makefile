# New ports collection makefile for:	ja-mutt
# Date created:		4 Sep 2000
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	mutt
PORTVERSION=	${VERSION}.j${JP_VERSION}
CATEGORIES=	japanese mail
MASTER_SITES=	http://www.emaillab.org/mutt/1.3/ \
		http://ha4.seikyou.ne.jp/home/Kohtaro.Hitomi/mutt/ \
		http://www5.xdsl.ne.jp/~shuna/distfiles/mutt/ \
		ftp://ftp.mutt.org/pub/mutt/devel/
DISTNAME=	${PORTNAME}-${VERSION}i
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-ja${JP_VERSION}${EXTRACT_SUFX} \
		manual_ja-${VERSION:R}i-0${EXTRACT_SUFX}

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

VERSION=	1.3.17
JP_VERSION=	0

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl
.endif

DIFFDIR=	${WRKDIR}/${DISTNAME}-ja${JP_VERSION}
DIFFNAME=	${DISTNAME}-ja${JP_VERSION}.diff
SRCDOCDIR=	${WRKDIR}/manual_ja-${VERSION:R}i
DOCDIR=		${PREFIX}/share/doc/mutt

pre-patch:
	(cd ${WRKSRC}; ${PATCH} -p1 < ${DIFFDIR}/${DIFFNAME})

pre-configure:
	(cd ${WRKSRC}; aclocal -I m4)

post-install:
	${INSTALL_DATA} ${DIFFDIR}/README.JA-PATCH ${DOCDIR}
	${INSTALL_DATA} ${DIFFDIR}/manual-ja-patch.txt ${DOCDIR}
	${INSTALL_DATA} ${DIFFDIR}/mutt-ja.rc ${DOCDIR}/samples
	${INSTALL_DATA} ${DIFFDIR}/sample.muttrc-tt ${DOCDIR}/samples
	${INSTALL_DATA} ${DIFFDIR}/usage-japanese.txt ${DOCDIR}
	${INSTALL_DATA} ${SRCDOCDIR}/manual_ja.txt ${DOCDIR}
	${INSTALL_DATA} ${SRCDOCDIR}/manual_ja.tex ${DOCDIR}
	${INSTALL_DATA} ${SRCDOCDIR}/manual_ja.html ${DOCDIR}
	${INSTALL_DATA} ${SRCDOCDIR}/manual_ja.sgml ${DOCDIR}

.include <bsd.port.post.mk>
