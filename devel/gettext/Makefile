# New ports collection makefile for:   gettext
# Date created:        16 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	0.13.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gettext

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU gettext package

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		expat.4:${PORTSDIR}/textproc/expat2

CONFLICTS=      gettext-0.12.1* gettext-0.11* gettext-0.10*
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	ACLOCAL="${TRUE}" \
		AUTOCONF="${TRUE}" \
		AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}" \
		MAKEINFO="makeinfo --no-split" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-libexpat-prefix=${LOCALBASE}/lib \
		--mandir=${PREFIX}/man
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

INFO=		autosprintf gettext

post-install:
.for f in po-compat.el po-mode.el
	${INSTALL_DATA} ${WRKSRC}/gettext-tools/misc/${f} ${PREFIX}/share/emacs/site-lisp
.endfor
	${MKDIR} ${X11BASE}/share/locale

.include <bsd.port.mk>
