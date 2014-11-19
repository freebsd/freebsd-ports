# Created by: Yukihiro Nakai <Nakai@technologist.com>
# $FreeBSD$

PORTNAME=	gettext
PORTVERSION=	0.18.3.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gettext

# note: before committing to this port, contact portmgr to arrange for an
# experimental ports run.  Untested commits may be backed out at portmgr's
# discretion.
MAINTAINER=	autotools@FreeBSD.org
COMMENT=	GNU gettext package

USES=		charsetfix iconv libtool:oldver
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-csharp --disable-java \
		--disable-openmp --disable-threads \
		--with-included-gettext --with-included-glib \
		--with-included-libcroco --with-included-libunistring \
		--with-included-libxml ${ICONV_CONFIGURE_ARG} \
		--without-emacs --without-git
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

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
	@${SETENV} ${MAKE_ENV} ${MAKE_CMD} -C ${WRKSRC}/gettext-tools/doc \
		${MAKE_ARGS} install-info-am

.include <bsd.port.mk>
