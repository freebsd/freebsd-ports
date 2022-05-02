# Run autoreconf in AUTORECONF_WRKSRC to update configure, Makefile.in and
# other build scripts.
#
# Autoreconf runs the following commands provided by devel/autoconf and
# devel/automake.  Each command applies to a single configure.ac or
# configure.in (old name).  If configure.ac defines subdirectories with their
# own configure.ac (using AC_CONFIG_SUBDIRS), autoreconf will recursively
# update those as well.
#
# aclocal	Looks up definitions of m4 macros used in configure.ac that are
#		not provided by autoconf and copies them from their source *.m4
#		file to aclocal.m4.  Local *.m4 files included with the source
#		code take precedence over systemwide *.m4 files.
# autoconf	Generates configure from configure.ac using macro definitions
#		provided by autoconf itself and aclocal.m4.
# autoheader	Generates a configuration header (typically config.h.in) from
#		configure.ac and the macro definitions in aclocal.m4.  Run by
#		autoreconf if configure.ac (or one of the macros it uses)
#		contains AC_CONFIG_HEADERS, AC_CONFIG_HEADER (undocumented), or
#		AM_CONFIG_HEADER (obsolete).
# automake	Generates Makefile.in from Makefile.am for each Makefile
#		listed in configure.ac (using AC_CONFIG_FILES).  Also updates
#		build scripts like compile, depcomp, install-sh, ylwrap,...
#		Run by autoreconf if configure.ac (or one of the macros it
#		uses) contains AM_INIT_AUTOMAKE.
#
# Autoreconf may also run these additional commands provided by other ports.
# A port needs to have a build depdendency on these ports when that's the case.
#
# autopoint	Provided by devel/gettext-tools.  Updates gettext related *.m4
#		files included with the source code and build scripts such as
#		config.rpath.  Run by autoreconf if configure.ac (or one of the
#		macros it uses) contains AM_GNU_GETTEXT.  A build dependency on
#		devel/gettext-tools can be added with USES+=gettext-tools.
#		Note that autoreconf runs autopoint even if a port has an NLS
#		option and the option is disabled.  The build dependency on
#		gettext-tools is not optional.  If the run dependency on
#		gettext is optional this can be specified with
#		NLS_USES=gettext-runtime.
# gtkdocize	Provided by textproc/gtk-doc.  Updates gtk-doc related *.m4
#		files included with the source code and build scripts such as
#		gtk-doc.make.  Run by autoreconf if configure.ac contains
#		GTK_DOC_CHECK.  The build dependency can be made optional with
#		DOCS option and DOCS_BUILD_DEPENDS+=gtkdocize:textproc/gtk-doc
#		on condition that you remove GTK_DOC_CHECK from configure.ac,
#		for instance using a post-patch-DOCS-off target with the
#		following command:
#		@${REINPLACE_CMD} /^GTK_DOC_CHECK/d ${WRKSRC}/configure.ac
#		It is likely that more patching is needed to eliminate or avoid
#		use of gtk-doc.
# intltoolize	Provided by textproc/intltool.  Updates intltool related *.m4
#		files included with the source code and build scripts such as
#		po/Makefile.in.in.  Run by autoreconf if configure.ac contains
#		(AC|IT)_PROG_INTLTOOL.  A build dependency on textproc/intltool
#		can be added with USES+=gnome and USE_GNOME+=intltool.
# libtoolize	Provided by devel/libtool.  Updates libtool related *.m4 files
#		included with the source code and build scripts such as
#		ltmain.sh.  Run by autoreconf if configure.ac  (or one of the
#		macros it uses) contains AC_PROG_LIBTOOL or LT_INIT.  A build
#		dependency on devel/libtool is added implicitly when USES
#		contains both autoreconf and libtool.
#
# Feature:	autoreconf
# Usage:	USES=autoreconf or USES=autoreconf:args
# Valid args:	build	Don't run autoreconf, only add build dependencies
#
# MAINTAINER:	ports@FreeBSD.org

.if !defined(_INCLUDE_USES_AUTORECONF_MK)
_INCLUDE_USES_AUTORECONF_MK=	yes
_USES_POST+=	autoreconf

AUTORECONF?=	${LOCALBASE}/bin/autoreconf
AUTORECONF_WRKSRC?=	${WRKSRC}

.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_AUTORECONF_POST_MK)
_INCLUDE_USES_AUTORECONF_POST_MK=	yes

BUILD_DEPENDS+=	autoconf>=2.69:devel/autoconf \
		automake>=1.16.1:devel/automake

.  if defined(libtool_ARGS) && empty(libtool_ARGS:Mbuild)
BUILD_DEPENDS+=	libtoolize:devel/libtool
.  endif

.  if empty(autoreconf_ARGS)
_USES_configure+=	470:do-autoreconf
do-autoreconf:
.    for f in AUTHORS ChangeLog INSTALL NEWS README
# Don't modify time stamps if the files already exist
	@test -e ${AUTORECONF_WRKSRC}/${f} || ${TOUCH} ${AUTORECONF_WRKSRC}/${f}
.    endfor
	@(cd ${AUTORECONF_WRKSRC} && \
		if test -f configure.ac; then configure=configure.ac; \
		else configure=configure.in; fi && \
		if ${GREP} -q '^GTK_DOC_CHECK' $${configure}; \
		then if ! ${LOCALBASE}/bin/gtkdocize --copy; then \
		${ECHO_MSG} '===>  Mk/Uses/autoreconf.mk: Error running gtkdocize'; \
		${FALSE}; fi; fi && \
		if ${EGREP} -q '^(AC|IT)_PROG_INTLTOOL' $${configure}; \
		then if ! ${LOCALBASE}/bin/intltoolize -f -c; then \
		${ECHO_MSG} '===>  Mk/Uses/autoreconf.mk: Error running intltoolize'; \
		${FALSE}; fi; fi)
	@(cd ${AUTORECONF_WRKSRC} && if ! ${AUTORECONF} -f -i; then \
		${ECHO_MSG} '===>  Mk/Uses/autoreconf.mk: Error running ${AUTORECONF}'; \
		${FALSE}; fi)
.  elif ! ${autoreconf_ARGS:Mbuild}
IGNORE= Incorrect 'USES+=autoreconf:${autoreconf_ARGS}' expecting 'USES+=autoreconf[:build]'
.  endif

.endif
