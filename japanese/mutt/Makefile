# New ports collection makefile for:	ja-mutt
# Date created:		5 Sep 1999
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#
# WITH_MUTT_CYRUS_SASL:	if defined, 'Cyrus sasl' support.
#

PORTNAME=	mutt
PORTVERSION=	${VERSION}.j${JP_VERSION}
PORTREVISION=	2
CATEGORIES=	japanese mail
MASTER_SITES=	http://www.emaillab.org/mutt/1.4/ \
		http://my.reset.jp/~iwashita/mutt/distfiles/ \
		http://ha4.seikyou.ne.jp/home/Kohtaro.Hitomi/mutt/ \
		ftp://ftp.mutt.org/pub/mutt/devel/
DISTNAME=	${PORTNAME}-${VERSION}i
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-ja.${JP_VERSION}${EXTRACT_SUFX} \
		manual_ja-${MANUALVERSION}i-1${EXTRACT_SUFX}
DIST_SUBDIR=	mutt

MAINTAINER=	iwashita@cqmail.net
COMMENT=	Text-based mail client (Japanised Version)

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang \
		iconv.3:${PORTSDIR}/converters/libiconv
.if !defined(WITH_GETTEXT)
USE_GETTEXT=	yes
.else
BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
LIB_DEPENDS+=	sasl.8:${PORTSDIR}/security/cyrus-sasl
.endif
RUN_DEPENDS=	urlview:${PORTSDIR}/textproc/urlview

VERSION=	1.4.1
JP_VERSION=	1
MANUALVERSION=	1.4

FETCH_BEFORE_ARGS=	-A	# ha4.seikyou.ne.jp is running broken httpd

USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
USE_OPENSSL=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSION}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include -I${LOCALBASE}/include/slang"
CONFIGURE_ARGS=	--with-slang --enable-locales-fix \
		--with-libiconv-prefix=${LOCALBASE} \
		--without-wc-funcs \
		--enable-flock --disable-fcntl \
		--with-ssl \
		--sysconfdir=${PREFIX}/etc \
		--with-docdir=${DOCSDIR} \
		--enable-pop --enable-imap \
		--enable-default-japanese
.if defined(WITH_GETTEXT)
CONFIGURE_ARGS+=	--with-included-gettext
.endif
.if defined(WITH_MUTT_CYRUS_SASL)
CONFIGURE_ARGS+=	--with-sasl=${LOCALBASE}
.endif

NOMANCOMPRESS=	yes
MAN1=		flea.1 mutt.1 muttbug.1 mutt_dotlock.1
MAN5=		muttrc.5 mbox.5

DIFFDIR=	${WRKDIR}/${DISTNAME}-ja.${JP_VERSION}
DIFFNAME=	patch-${VERSION}.tt.ja.${JP_VERSION}

pre-patch:
	(cd ${DIFFDIR}; ${PATCH} < ${FILESDIR}/prepatch-aa)
	(cd ${WRKSRC}; ${PATCH} -p1 < ${DIFFDIR}/${DIFFNAME})

pre-configure:
.if defined(NOPORTDOCS)
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extrapatch-nodoc-aa
	${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extrapatch-nodoc-ab
.endif
	(cd ${WRKSRC}; ${ACLOCAL} -I m4)

post-configure:
	@${REINPLACE_CMD} -E "\
		s|^(s%\@ACLOCAL\@%).+(%g)|\1${ACLOCAL}\2|; \
		s|^(s%\@AUTOCONF\@%).+(%g)|\1${AUTOCONF}\2|; \
		s|^(s%\@AUTOMAKE\@%).+(%g)|\1${AUTOMAKE}\2|; \
		s|^(s%\@AUTOHEADER\@%).+(%g)|\1${AUTOHEADER}\2|" \
		${BUILD_WRKSRC}/config.status

.if !defined(NOPORTDOCS)
post-install:
	${INSTALL_DATA} ${DIFFDIR}/INSTALL.JA-PATCH.ja ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/INSTALL.ja ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/NEWS.ja ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/PGP-Notes.ja.txt ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/README.JA-PATCH.ja ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/README.SECURITY.ja ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/README.SSL.ja ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/README.ja ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/applying-patches.ja.txt ${DOCSDIR}
	${INSTALL_DATA} ${DIFFDIR}/html/INSTALL.JA-PATCH.ja.html ${DOCSDIR}/html
	${INSTALL_DATA} ${DIFFDIR}/html/README.JA-PATCH.ja.html ${DOCSDIR}/html
	${INSTALL_DATA} ${DIFFDIR}/html/manual-ja-patch.en.html ${DOCSDIR}/html
	${INSTALL_DATA} ${DIFFDIR}/html/manual-ja-patch.ja.html ${DOCSDIR}/html
	${INSTALL_DATA} ${DIFFDIR}/html/usage-japanese.ja.html ${DOCSDIR}/html
	${INSTALL_DATA} ${DIFFDIR}/samples/mutt-en.rc ${DOCSDIR}/samples
	${INSTALL_DATA} ${DIFFDIR}/samples/mutt-ja.rc ${DOCSDIR}/samples
	${INSTALL_DATA} ${DIFFDIR}/samples/sample.muttrc-tt ${DOCSDIR}/samples
	${INSTALL_DATA} ${WRKDIR}/manual_ja.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.tex ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.sgml ${DOCSDIR}
.endif

.include <bsd.port.mk>
