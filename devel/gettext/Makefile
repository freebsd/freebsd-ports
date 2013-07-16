# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$

PORTNAME=	gettext
PORTVERSION=	0.18.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gettext

# note: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	autotools@FreeBSD.org
COMMENT=	GNU gettext package

USES=		charsetfix iconv
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-csharp --disable-java \
		--disable-openmp --disable-threads \
		--with-included-gettext --with-included-glib \
		--with-included-libcroco --with-included-libunistring \
		--with-included-libxml \
		--without-emacs --without-git
USE_LDCONFIG=	yes

MAN1=		autopoint.1 envsubst.1 gettext.1 gettextize.1 msgattrib.1 \
		msgcat.1 msgcmp.1 msgcomm.1 msgconv.1 msgen.1 msgexec.1 \
		msgfilter.1 msgfmt.1 msggrep.1 msginit.1 msgmerge.1 \
		msgunfmt.1 msguniq.1 ngettext.1 recode-sr-latin.1 xgettext.1
MAN3=		bind_textdomain_codeset.3 bindtextdomain.3 dcgettext.3 \
		dcngettext.3 dgettext.3 dngettext.3 gettext.3 ngettext.3 \
		textdomain.3
INFO=		autosprintf gettext

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MDOCS}
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-nodocs
.endif

post-patch:
.if ! ${PORT_OPTIONS:MDOCS}
.for dir in runtime tools
	@${REINPLACE_CMD} -e 's|^SUBDIRS = doc|SUBDIRS =|' \
		${WRKSRC}/gettext-${dir}/Makefile.in
.endfor
.endif

post-install:
	@${MKDIR} ${LOCALBASE}/share/locale
	@cd ${WRKSRC}/gettext-tools/doc && make install-info-am

.include <bsd.port.mk>
