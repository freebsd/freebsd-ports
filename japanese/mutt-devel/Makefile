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
		http://www5.xdsl.ne.jp/~shuna/mutt/distfiles/ \
		ftp://ftp.mutt.org/pub/mutt/devel/
DISTNAME=	${PORTNAME}-${VERSION}i
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-ja.${JP_VERSION}${EXTRACT_SUFX} \
		manual_ja-${MANUALVERSION}i-0${EXTRACT_SUFX}

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

VERSION=	1.3.25
JP_VERSION=	1
MANUALVERSION=	1.3.23

DIST_SUBDIR=	mutt
NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSION}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-slang --enable-locales-fix \
		--with-libiconv-prefix=${PREFIX} \
		--without-wc-funcs \
		--enable-flock --disable-fcntl \
		--sysconfdir=${PREFIX}/etc \
		--with-docdir=${PREFIX}/share/doc/mutt \
		--enable-pop --enable-imap \
		--enable-default-japanese
.if defined(WITH_GETTEXT)
CONFIGURE_ARGS+=	--with-included-gettext
.endif

FETCH_BEFORE_ARGS=	-A	# ha4.seikyou.ne.jp is running broken httpd

NOMANCOMPRESS=	yes
MAN1=		flea.1 mutt.1 muttbug.1 mutt_dotlock.1
MAN5=		muttrc.5 mbox.5

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl
.endif

DIFFDIR=	${WRKDIR}/${DISTNAME}-ja.${JP_VERSION}
DIFFNAME=	patch-${VERSION}.tt.ja.${JP_VERSION}
SRCDOCSDIR=	${WRKDIR}/manual_ja-${MANUALVERSION}

pre-patch:
	(cd ${DIFFDIR}; ${PATCH} < ${FILESDIR}/prepatch-aa)
	(cd ${WRKSRC}; ${PATCH} -p1 < ${DIFFDIR}/${DIFFNAME})

pre-configure:
	(cd ${WRKSRC}; ${ACLOCAL} -I m4)

post-configure:
	@${PERL} -pi -e "\
		s/^(s%\@ACLOCAL\@%).+(%g)/\1${ACLOCAL}\2/; \
		s/^(s%\@AUTOCONF\@%).+(%g)/\1${AUTOCONF}\2/; \
		s/^(s%\@AUTOMAKE\@%).+(%g)/\1${AUTOMAKE}\2/; \
		s/^(s%\@AUTOHEADER\@%).+(%g)/\1${AUTOHEADER}\2/" \
		${BUILD_WRKSRC}/config.status

post-install:
	${INSTALL_DATA} ${DIFFDIR}/INSTALL.JA-PATCH.en ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/INSTALL.JA-PATCH.ja ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/README.JA-PATCH.en ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/README.JA-PATCH.ja ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/html/manual-ja-patch.en.html ${DOCSDIR}/html
	${INSTALL_DATA} ${DIFFDIR}/html/manual-ja-patch.ja.html ${DOCSDIR}/html
	${INSTALL_DATA} ${DIFFDIR}/html/usage-japanese.en.html ${DOCSDIR}/html
	${INSTALL_DATA} ${DIFFDIR}/html/usage-japanese.ja.html ${DOCSDIR}/html
	${INSTALL_DATA} ${DIFFDIR}/samples/mutt-en.rc ${DOCSDIR}/samples
	${INSTALL_DATA} ${DIFFDIR}/samples/mutt-ja.rc ${DOCSDIR}/samples
	${INSTALL_DATA} ${DIFFDIR}/samples/sample.muttrc-tt ${DOCSDIR}/samples
	${INSTALL_DATA} ${SRCDOCSDIR}/manual_ja.txt ${DOCSDIR}
	${INSTALL_DATA} ${SRCDOCSDIR}/manual_ja.tex ${DOCSDIR}
	${INSTALL_DATA} ${SRCDOCSDIR}/manual_ja.html ${DOCSDIR}
	${INSTALL_DATA} ${SRCDOCSDIR}/manual_ja.sgml ${DOCSDIR}

.include <bsd.port.post.mk>
