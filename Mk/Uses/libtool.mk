# $FreeBSD$
#
# Bring libtool scripts up to date.
#
# Feature:	libtool
# Usage:	USES=libtool or USES=libtool:args
# Valid args:	keepla	Don't remove libtool libraries (*.la) from the stage
#			directory.  Some ports need them at runtime (e.g. ports
#			that call lt_dlopen from libltdl).
#		build	Add a build dependency on devel/libtool.  This can
#			be used when a port does not generate its own libtool
#			script and relies on the system to provide one.
#
# MAINTAINER:	autotools@FreeBSD.org

.if !defined(_INCLUDE_USES_LIBTOOL_MK)
_INCLUDE_USES_LIBTOOL_MK=	yes
_USES_POST+=	libtool

.if ${libtool_ARGS:Mbuild}
BUILD_DEPENDS+=	libtool:${PORTSDIR}/devel/libtool
.endif
.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_LIBTOOL_POST_MK)
_INCLUDE_USES_LIBTOOL_POST_MK=	yes

_USES_configure+=	480:patch-libtool
patch-libtool:
	@${FIND} ${WRKDIR} \( -name configure -or -name ltconfig \)	\
		-type f | while read i; do ${SED} -i.libtool.bak	\
		-e '/dragonfly\*/!s/^ *freebsd\*[ )]/dragonfly* | &/'	\
		-e '/gcc_dir=\\`/s/gcc /$$CC /'				\
		-e '/gcc_ver=\\`/s/gcc /$$CC /'				\
		-e '/link_all_deplibs[0-9A-Z_]*=/s/=unknown/=no/'	\
		-e '/archive_expsym_cmds[0-9A-Z_]*=.$$CC.*-retain-/ {	\
		    s/-retain-symbols-file/-version-script/;		\
		    s/$$export_symbols/$$lib-ver/;			\
		    s/$$CC/echo "{ global:" > $$lib-ver~		\
		    sed -e "s|$$|;|" < $$export_symbols >> $$lib-ver~	\
		    echo "local: *; };" >> $$lib-ver~&/; }'		\
		-e '/objformat=/s/echo aout/echo elf/'			\
		-e '/STRIP -V/s/"GNU strip"/"strip"/'			\
		-e "/freebsd-elf\\*)/,/;;/ {				\
		    /deplibs_check_method=/s/=.*/=pass_all/;		\
		    /library_names_spec=.*\\.so/			\
		    s/=.*/='\$$libname\$$release.so\$$versuffix		\
			\$$libname\$$release.so\$$major \$$libname.so'	\
		    soname_spec='\$$libname\$$release.so\$$major'/;	\
		    /library_names_spec=.*shared_ext/			\
		    s/=.*/='\$$libname\$$release\$$shared_ext\$$versuffix \
			\$$libname\$$release\$$shared_ext\$$major	\
			\$$libname\$$shared_ext'			\
		    soname_spec='\$$libname\$$release\$$shared_ext\$$major'/; \
		    }" $${i} && ${TOUCH} -mr $${i}.libtool.bak $${i}; done

	@${FIND} ${WRKDIR} -type f -name ltmain.sh |			\
		${XARGS} ${REINPLACE_CMD}				\
		-e '/case $$version_type in/,+2				\
		    s/darwin|linux|/darwin|freebsd-elf|linux|/'		\
		-e '/freebsd-elf)/,+2 {					\
		    /major=/s/=.*/=.$$(($$current - $$age))/;		\
		    /versuffix=/s/=.*/="$$major.$$age.$$revision"/; }'	\
		-e '/if.*linkmode.*prog.*mode.*!= relink/s/if.*;/if :;/'\
		-e '/if.*prog.*linkmode.*relink !=.*mode/s/if.*;/if :;/'\
		-e '/if.*linkmode.*prog.*mode.* = relink/s/||.*;/;/'	\
		-e '/if.*prog.*linkmode.*relink = .*mode/s/||.*;/;/'	\
		-e 's/|-p|-pg|/|-B*|-fstack-protector*|-p|-pg|/'

_USES_stage+=	790:patch-lafiles
patch-lafiles:
.if ${libtool_ARGS:Mkeepla}
	@${FIND} ${STAGEDIR} -type f -name '*.la' |			\
		${XARGS} ${SED} -i '' -e "/dependency_libs=/s/=.*/=''/"
.else
	@${FIND} ${STAGEDIR} -type l -exec ${SH} -c			\
		'case `${REALPATH} -q "{}"` in				\
			*.la) ${ECHO_CMD} "{}" ;; esac' \; |		\
		${XARGS} ${GREP} -l 'libtool library' | ${XARGS} ${RM}
	@${FIND} ${STAGEDIR} -type f -name '*.la' |			\
		${XARGS} ${GREP} -l 'libtool library' | ${XARGS} ${RM}
.endif

.endif
