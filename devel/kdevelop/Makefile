# New ports collection makefile for:	kdevelop
# Version required:	1.0 (final)
# Date created:		12 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	kdevelop-1.0
CATEGORIES=	devel
MASTER_SITES=	ftp://fara.cs.uni-potsdam.de/pub/kdevelop/ \
		ftp://129.187.206.68/pub/unix/ide/KDevelop/ \
		ftp://ftp.bawue.de/pub/unix/KDevelop/ \
		ftp://ftp.chg.ru/pub/X11/kdevelop/ \
		ftp://ftp.weltopia.com/pub/kdevelop/ \
		ftp://gd.tuwien.ac.at/hci/KDevelop/ \
		ftp://altair.dhs.org/pub/kdevelop/

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	kdeui.3:${PORTSDIR}/x11/kdelibs11
RUN_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes
USE_QT=		yes
MAKE_ENV=	CXX="${CXX}"
CONFIGURE_ENV=	CXX="${CXX}" QTINC=${X11BASE}/include/X11/ \
		QTLIB=${X11BASE}
CONFIGURE_ARGS=	--prefix=${LOCALBASE} \
		--with-qtdoc-dir=${X11BASE}/share/doc/qt/html

.if !defined(USE_OPTIONAL_RUNDEPENDS)
pre-patch:
	@${ECHO}
	@${ECHO} "You may define USE_OPTIONAL_RUNDEPENDS (make USE_OPTIONAL_RUNDEPENDS=YES)"
	@${ECHO} "to automatically build the suggested programs to compliment kdevelop."
	@${ECHO}
	@sleep 3
.else
RUN_DEPENDS+=	automake:${PORTSDIR}/devel/automake \
		kdbg:${PORTSDIR}/devel/kdbg \
		ktranslator:${PORTSDIR}/devel/ktranslator \
		glimpse:${PORTSDIR}/textproc/glimpse \
		a2ps:${PORTSDIR}/print/a2ps43-letter
.endif

.include <bsd.port.mk>
