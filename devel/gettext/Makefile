# New ports collection makefile for:   gettext
# Date created:        16 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	0.14.5
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gettext

MAINTAINER=	ade@FreeBSD.org
COMMENT=	GNU gettext package

USE_ICONV=	yes
LIBTOOLFILES=	autoconf-lib-link/configure gettext-runtime/configure \
		gettext-runtime/libasprintf/configure gettext-tools/configure
USE_LIBTOOL_VER=15
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	ACLOCAL="${TRUE}" \
		AUTOCONF="${TRUE}" \
		AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}" \
		MAKEINFO="makeinfo --no-split" \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-csharp \
		--mandir=${PREFIX}/man
INSTALLS_SHLIB=	yes

.if !defined(WITHOUT_GETTEXT_OPTIONS)
OPTIONS=	EXAMPLES "install example files" off \
		HTMLMAN "install man pages in HTML format" off
.endif
PLIST=		${WRKDIR}/plist
PLISTU=		${WRKDIR}/plist-unsorted
PLIST_SUB=	LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} \
		VERSION=${PORTVERSION}

MAN1=		autopoint.1 gettext.1 gettextize.1 msgattrib.1 msgcat.1 \
		msgcmp.1 msgcomm.1 msgconv.1 msgen.1 msgexec.1 \
		msgfilter.1 msgfmt.1 msggrep.1 msginit.1 msgmerge.1 \
		msgunfmt.1 msguniq.1 ngettext.1 xgettext.1 envsubst.1
MAN3=		bind_textdomain_codeset.3 bindtextdomain.3 dcgettext.3 \
		dcngettext.3 dgettext.3 dngettext.3 gettext.3 ngettext.3 \
		textdomain.3
HTML=		gettext.3 ngettext.3 textdomain.3 \
		bindtextdomain.3 bind_textdomain_codeset.3

INFO=		autosprintf gettext

.ifdef USE_GETTEXT
.error	USE_GETTEXT is defined as an environment variable, or in the arguments \
	to "make".  Please unset it and restart the build.
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
CONFIGURE_ARGS+=	--with-libexpat-prefix=${LOCALBASE}/lib
LIB_DEPENDS+=	expat.5:${PORTSDIR}/textproc/expat2
.endif

pre-extract:
.if exists(${PREFIX}/bin/kaffe)
	@${ECHO_MSG} "Gettext won't build with Kaffe's jar utility.  Doing:"
	-${MV} ${PREFIX}/bin/jar ${PREFIX}/bin/jar.backup
	@${ECHO_MSG} "Be sure to mv" ${PREFIX}/bin/jar.backup ${PREFIX}/bin/jar
	@${ECHO_MSG} "if you abandon your attempt to build gettext."
	@sleep 5
.endif

post-build:
.if exists(${PREFIX}/bin/kaffe)
	-${MV} ${PREFIX}/bin/jar.backup ${PREFIX}/bin/jar
	@${ECHO_MSG}
	@${ECHO_MSG} "Your" ${PREFIX}/bin/jar "has been restored."
	@sleep 5
.endif

pre-install:
	@${RM} -f ${PLISTU}
	@${TOUCH} ${PLISTU}
.if !defined (NOPORTDOCS)
.for ii in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 foot toc
	${ECHO_CMD} %%DOCSDIR%%/gettext_${ii}.html >> ${PLISTU}
.endfor
.endif
.if defined (WITH_HTMLMAN)
.for ii in ${MAN1} ${HTML}
	${ECHO_CMD} %%DOCSDIR%%/${ii}.html >> ${PLISTU}
.endfor
.endif
.if defined (WITH_EXAMPLES)
	cd ${WRKSRC}/gettext-tools && \
		${FIND} -s examples -type f | ${GREP} -vw examples/po | \
		${GREP} -v ChangeLog | ${GREP} -v examples/Makefile | \
		${GREP} -v examples/installpaths.in | \
		${SED} 's:^:share/doc/gettext/:' >> ${PLISTU} && \
		${FIND} -d examples -type d | ${GREP} -v examples/po | \
		${GREP} / | ${SED} -e 's:^:@dirrm share/doc/gettext/:' \
		>> ${PLISTU}
.endif
	@${CAT} ${.CURDIR}/pkg-plist ${PLISTU} | ${GREP} -v ^@ > ${PLIST}
	@${SORT} -r ${.CURDIR}/pkg-plist ${PLISTU} | ${GREP} ^@dirrm >> ${PLIST}
	@${GREP} -h ^@ ${.CURDIR}/pkg-plist ${PLISTU} | ${GREP} exec >> ${PLIST}

post-install:
.for f in po-compat.el po-mode.el
	${INSTALL_DATA} ${WRKSRC}/gettext-tools/misc/${f} ${PREFIX}/share/emacs/site-lisp
.endfor
	${MKDIR} ${X11BASE}/share/locale
	cd ${WRKSRC}/gettext-tools/doc && make install-info-am
.if !defined (NOPORTDOCS)
	cd ${WRKSRC}/gettext-runtime/doc && make install-data
	cd ${WRKSRC}/gettext-tools/doc && make install-data-local
.endif
.if defined (WITH_EXAMPLES)
	cd ${WRKSRC}/gettext-tools/examples && make install
.endif
.if !defined (WITH_HTMLMAN)
	cd ${WRKSRC}/gettext-runtime/man && make uninstall-html
	cd ${WRKSRC}/gettext-tools/man && make uninstall-html
.endif

.include <bsd.port.post.mk>
