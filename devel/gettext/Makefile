# New ports collection makefile for:   gettext
# Date created:        16 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	0.11.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gettext

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		expat.4:${PORTSDIR}/textproc/expat2

USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	ACLOCAL="${TRUE}" \
		AUTOCONF="${TRUE}" \
		AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}" \
		MAKEINFO="makeinfo --no-split" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-libexpat-prefix=${LOCALBASE}/lib
INSTALLS_SHLIB=	yes

PLIST_SUB=	LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} \
		VERSION=${PORTVERSION}

MAN1=		autopoint.1 gettext.1 gettextize.1 msgattrib.1 msgcat.1 \
		msgcmp.1 msgcomm.1 msgconv.1 msgen.1 msgexec.1 \
		msgfilter.1 msgfmt.1 msggrep.1 msginit.1 msgmerge.1 \
		msgunfmt.1 msguniq.1 ngettext.1 xgettext.1
MAN3=		bind_textdomain_codeset.3 bindtextdomain.3 dcgettext.3 \
		dcngettext.3 dgettext.3 dngettext.3 gettext.3 ngettext.3 \
		textdomain.3

pre-configure:
	${RM} ${WRKSRC}/doc/gettext.info*

post-install:
	@install-info ${PREFIX}/info/gettext.info ${PREFIX}/info/dir
	${MKDIR} ${PREFIX}/share/emacs/site-lisp
.for file in po-compat.el po-mode.el
	${INSTALL_DATA} ${WRKSRC}/misc/${file} ${PREFIX}/share/emacs/site-lisp
.endfor
	${MKDIR} ${X11BASE}/share/locale

.include <bsd.port.mk>
