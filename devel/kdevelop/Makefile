# New ports collection makefile for:	kdevelop
# Version required:	1.1 (final)
# Date created:		12 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	kdevelop-1.1
CATEGORIES=	devel
MASTER_SITES=	ftp://fara.cs.uni-potsdam.de/pub/kdevelop/ \
		ftp://129.187.206.68/pub/unix/ide/KDevelop/ \
		ftp://ftp.bawue.de/pub/unix/KDevelop/ \
		ftp://ftp.chg.ru/pub/X11/kdevelop/ \
		ftp://gd.tuwien.ac.at/hci/KDevelop/ \
		ftp://altair.dhs.org/pub/kdevelop/ \
		ftp://apcs.shellx.org/pub/KDevelop/ \
		ftp://ftp.mpg.goe.ni.schule.de/pub/linux/ide/KDevelop/

MAINTAINER=	andrews@technologist.com

LIB_DEPENDS=	kdeui.3:${PORTSDIR}/x11/kdelibs11
RUN_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

.if defined(USE_OPTIONAL_DEPENDS)
RUN_DEPENDS+=	automake:${PORTSDIR}/devel/automake \
		kdbg:${PORTSDIR}/devel/kdbg \
		${LOCALBASE}/share/doc/HTML/en/kdelibs/kdecore/index.html:${PORTSDIR}/devel/kdelibdocs \
		ktranslator:${PORTSDIR}/devel/ktranslator \
		kiconedit:${PORTSDIR}/graphics/kdegraphics11 \
		glimpse:${PORTSDIR}/textproc/glimpse \
		a2ps:${PORTSDIR}/print/a2ps43-letter
.endif

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_QT=		yes
CONFIGURE_ARGS=	--with-qtdoc-dir=${X11BASE}/share/doc/qt/html \
		--with-qt-includes=${X11BASE}/include/X11/qt \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib
MAKE_ENV=	CXX="${CXX}" SOMAJOR="${SOMAJOR}" SOMINOR="${SOMINOR}"
SOMAJOR=        1
SOMINOR=        0

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "aout"
LIBVER="${SOMAJOR}.${SOMINOR}"
.else
LIBVER="${SOMAJOR}"
.endif
PLIST_SUB+=	LIBVER="${LIBVER}"

pre-patch:
.if !defined(USE_OPTIONAL_DEPENDS)
	@${ECHO}
	@${ECHO} "You may define USE_OPTIONAL_DEPENDS (make USE_OPTIONAL_DEPENDS=YES)"
	@${ECHO} "to automatically build the suggested programs to compliment kdevelop."
	@${ECHO}
	@sleep 1
.endif

post-patch:
	@${LN} -sf /usr/include/g++/FlexLexer.h ${WRKSRC}

.include <bsd.port.post.mk>
