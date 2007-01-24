# New ports collection makefile for:	smalltalk
# Date created:		09 Feb 1995
# Whom:			gpalmer
#
# $FreeBSD$
#

PORTNAME=	smalltalk
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Smalltalk

LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm \
		execinfo.1:${PORTSDIR}/devel/libexecinfo

OPTIONS=	TCLTK "Enable Tcl/Tk binding" on

USE_GNOME=	gnomehack gnometarget pkgconfig
USE_GCC=	3.4+
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		ac_cv_prog_EMACS=no
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man \
		--infodir=${PREFIX}/${INFO_PATH} \
		--enable-generational-gc=no \
		--enable-gtk=no \
		--with-emacs=no \
		--with-gmp=no
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=		gst.1
INFO=		gst gst-base gst-libs

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "alpha"
BROKEN=		does not compile on !i386 and !alpha
.endif

.if ${OSVERSION} < 500000 || exists(${LOCALBASE}/lib/libreadline.so.5)
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif

.if defined(WITHOUT_TCLTK)
CONFIGURE_ARGS+=	--with-tcl=no
PLIST_SUB+=	TCLTK="@comment "
.else
LIB_DEPENDS+=	tk84.1:${PORTSDIR}/x11-toolkits/tk84
CONFIGURE_ARGS+=	--with-tcl=${LOCALBASE}/lib/tcl8.4 \
			--with-tk=${LOCALBASE}/lib/tk8.4
PLIST_SUB+=	TCLTK=""
.endif

post-build:
	@${SED} -e 's|@bindir@|${PREFIX}/bin|g' \
		${WRKSRC}/gst-mode.el.in > ${WRKSRC}/gst-mode.el
	@${SED} -e 's|@lispdir@|${PREFIX}/share/emacs/site-lisp|g' \
		${WRKSRC}/smalltalk-mode.el.in > ${WRKSRC}/smalltalk-mode.el

post-install:
	@${MKDIR} ${DATADIR}/gtk
	@${TOUCH} ${DATADIR}/gtk/.keep_me
	${INSTALL_DATA} ${WRKSRC}/*.el ${PREFIX}/share/emacs/site-lisp

.include <bsd.port.post.mk>
