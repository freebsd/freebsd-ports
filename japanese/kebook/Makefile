# New ports collection makefile for:   kebook-i18n
# Date created:        13 Novenver 1999
# Whom:                SUZUKI, Mitsuhiro <hige@higesoft.rim.or.jp>
#
# $FreeBSD$
#

PORTNAME=      kebook
PORTVERSION=   0.3.4
CATEGORIES=    japanese kde
MASTER_SITES=  http://www.os.rim.or.jp/~s_mitu/library/kebook/ \
		ftp://ftp.kde.gr.jp/pub/kde/unstable/contrib/
PKGNAMEPREFIX= ja-
PKGNAMESUFFIX= -i18n

MAINTAINER=     hige@higesoft.os.rim.or.jp

LIB_DEPENDS=    qti18n.3:${PORTSDIR}/x11-toolkits/qt-i18n \
		kdecore.2:${PORTSDIR}/x11/kdelibs11-i18n \
		kfm.2:${PORTSDIR}/x11/kdebase11-i18n \
		eb.3:${PORTSDIR}/japanese/eb

USE_BZIP2=      yes
USE_GMAKE=      yes
USE_NEWGCC=     yes
USE_LIBTOOL=    yes

CONFIGURE_ARGS= "--with-qt-includes=${QTDIR}/include/X11/qt" \
		"--with-eb-includes=$(LOCALBASE)/include" \
		"--with-eb-libraries=$(LOCALBASE)/lib" \
		"--with-extra-includes=${LOCALBASE}/include" \
		"--with-extra-libs=${LOCALBASE}/lib"
CONFIGURE_ENV=	CPPFLAGS=-I$(LOCALBASE)/include \
		LDFLAGS=-L$(LOCALBASE)/lib \
		X_EXTRA_LIBS="-lxpg4" \
		QTDIR=${QTDIR}
CXXFLAGS?=      ${CFLAGS}

DOCDIR=         share/apps/kebook/doc
PLIST_SUB=	DOCDIR=${DOCDIR}

.if defined(PREFIX)
QTDIR?=         ${PREFIX}
.else
QTDIR?=         ${X11BASE}
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${DOCDIR}
	@for i in AUTHORS COPYING ChangeLog NEWS README README.euc-jp INSTALL INSTALL.euc-jp; do \
		${INSTALL_DATA} ${WRKSRC}/$${i} ${PREFIX}/${DOCDIR} ;\
	done
.endif

.include <bsd.port.mk>
