# New ports collection makefile for:   gettext
# Date created:        16 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	0.10.38
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gettext

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	giconv.2:${PORTSDIR}/converters/libiconv

NO_LATEST_LINK=	yes

USE_BISON=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_SUB=	LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

MAN3=		bind_textdomain_codeset.3 bindtextdomain.3 dcgettext.3 \
		dcngettext.3 dgettext.3 dngettext.3 gettext.3 ngettext.3 \
		textdomain.3

# X X X - I know, but it doesn't work with BSD iconv yet. :(((
post-patch:
	@/usr/bin/find ${WRKSRC} -type f | xargs ${PERL} -pi -e \
		's|-liconv|-lgiconv|g ; s|iconv\.h|giconv\.h|g'

pre-configure:
	${RM} ${WRKSRC}/doc/gettext.info*

.if !defined(WANT_FULL_GETTEXT)
BINFILES=	gettext msgcmp msgcomm msgfmt msgmerge msgunfmt \
		ngettext xgettext
PLIST=		${WRKDIR}/PLIST
LIBTOOLFLAGS=	--disable-ltlibs --disable-shared
.undef MAN3
.undef INSTALLS_SHLIB

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/misc/gettextize \
		${PREFIX}/bin/gettextize-new
	@${ECHO} bin/gettextize-new > ${WRKDIR}/PLIST
.for file in ${BINFILES}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${file} ${PREFIX}/bin/${file}-new
	@${ECHO} bin/${file}-new >> ${WRKDIR}/PLIST
.endfor
.else
post-install:
	@install-info ${PREFIX}/info/gettext.info ${PREFIX}/info/dir
	${MKDIR} ${PREFIX}/share/emacs/site-lisp
	${INSTALL_DATA} ${WRKSRC}/misc/po-mode.el \
		${PREFIX}/share/emacs/site-lisp/po-mode.el
	${MKDIR} ${X11BASE}/share/locale
.endif

.include <bsd.port.mk>
