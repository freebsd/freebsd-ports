# New ports collection makefile for:	ja-mutt
# Date created:		5 Sep 1999
# Whom:			IWASHITA Yoji <shuna@pop16.odn.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	mutt
PORTVERSION=	${VERSION}.j${JP_VERSION}
CATEGORIES=	japanese mail
MASTER_SITES=	ftp://ftp.mutt.org/pub/mutt/ \
		http://ha4.seikyou.ne.jp/home/Kohtaro.Hitomi/mutt/ \
		http://www5.xdsl.ne.jp/~shuna/distfiles/mutt/ \
		ftp://ftp.gbnet.net/pub/mutt-international/ \
		ftp://ftp.guug.de/pub/mutt/ \
		ftp://ftp.guug.de/pub/mutt/historic/
DISTNAME=	${PORTNAME}-${VERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		manual_ja-${MANUALVERSION}i-2${EXTRACT_SUFX}

PATCH_SITES=	http://www.emaillab.org/mutt/1.2/ \
		http://www5.xdsl.ne.jp/~shuna/distfiles/mutt/
PATCHFILES=	${DISTNAME}i-jp${JP_VERSION}.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	shuna@pop16.odn.ne.jp

LIB_DEPENDS=	slang.2:${PORTSDIR}/japanese/libslang
.if !defined(WITH_GETTEXT)
LIB_DEPENDS+=	intl.1:${PORTSDIR}/devel/gettext
.endif
.if defined(WITH_GETTEXT)
BUILD_DEPENDS=	${LOCALBASE}/bin/msgfmt:${PORTSDIR}/devel/gettext
.endif
RUN_DEPENDS=	urlview:${PORTSDIR}/textproc/urlview

VERSION=	1.2.5.1
JP_VERSION=	0
MANUALVERSION=	1.2

FETCH_BEFORE_ARGS=	-A	# ha4.seikyou.ne.jp is running broken httpd

DIST_SUBDIR=	mutt
USE_GMAKE=	yes
USE_AUTOMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${VERSION}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-slang --enable-locales-fix \
		--enable-flock --disable-fcntl \
		--sysconfdir=${PREFIX}/etc \
		--with-docdir=${DOCSDIR} \
		--enable-pop --enable-imap
.if defined(WITH_GETTEXT)
CONFIGURE_ARGS+=	--with-included-gettext
.endif
MAN1=		mutt.1 mutt_dotlock.1
MAN5=		muttrc.5

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
	${INSTALL_DATA} ${WRKDIR}/manual_ja.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.tex ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/manual_ja.sgml ${DOCSDIR}

.include <bsd.port.mk>
