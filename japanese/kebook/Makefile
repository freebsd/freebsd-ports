# New ports collection makefile for:   kebook-i18n
# Date created:        13 Novenver 1999
# Whom:                SUZUKI, Mitsuhiro <hige@higesoft.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=	kebook
PORTVERSION=	0.3.5
CATEGORIES=	japanese kde
MASTER_SITES=	http://www.os.rim.or.jp/~s_mitu/library/kebook/ \
		ftp://ftp.kde.gr.jp/pub/kde/unstable/contrib/

MAINTAINER=	hige@higesoft.os.rim.or.jp

LIB_DEPENDS=	eb.3:${PORTSDIR}/japanese/eb
BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

USE_KDEBASE_VER=1
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS=	"--with-qt-dir=${QTDIR}" \
		"--with-qt-includes=${QTDIR}/include/X11/qt" \
		"--with-qt-libraries=${QTDIR}/lib" \
		"--with-eb-includes=${LOCALBASE}/include" \
		"--with-eb-libraries=${LOCALBASE}/lib" \
		"--with-extra-includes=${LOCALBASE}/include" \
		"--with-extra-libs=${LOCALBASE}/lib"
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib \
		QTDIR=${QTDIR}

CXXFLAGS?=	${CFLAGS}

DOCDIR=		share/apps/kebook/doc
PLIST_SUB=	DOCDIR=${DOCDIR}

.if defined(PREFIX)
QTDIR?=		${PREFIX}
.else
QTDIR?=		${X11BASE}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400020 || ( ${OSVERSION} >= 500000 && ${OSVERSION} < 500005 )
CONFIGURE_ENV+=	X_EXTRA_LIBS="-lxpg4"
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
	@for i in AUTHORS COPYING ChangeLog NEWS README README.euc-jp INSTALL INSTALL.euc-jp; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${DOCDIR} ;\
	done
.endif

.include <bsd.port.post.mk>
