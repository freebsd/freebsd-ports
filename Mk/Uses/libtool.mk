# $FreeBSD$
#
# Bring libtool scripts up to date.
#
# Feature:	libtool
# Usage:	USES=libtool
#
# MAINTAINER:	autotools@FreeBSD.org

.if !defined(_INCLUDE_USES_LIBTOOL_MK)
_INCLUDE_USES_LIBTOOL_MK=	yes
_USES_POST+=	libtool
libtool_ARGS?=
.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_LIBTOOL_POST_MK)
_INCLUDE_USES_LIBTOOL_POST_MK=	yes

patch-libtool:
	@${FIND} ${WRKDIR} \( -name configure -or -name ltconfig \)	\
		-type f | ${XARGS} ${REINPLACE_CMD}			\
		-e '/dragonfly\*/!s/^ *freebsd\*[ )]/dragonfly* | &/'	\
		-e '/gcc_dir=\\`/s/gcc /$$CC /'				\
		-e '/gcc_ver=\\`/s/gcc /$$CC /'				\
		-e '/link_all_deplibs[0-9A-Z_]*=/s/=unknown/=no/'	\
		-e '/objformat=/s/echo aout/echo elf/'			\
		-e "/freebsd-elf\\*)/,/;;/ {				\
		    /deplibs_check_method=/s/=.*/=pass_all/; }"	

	@${FIND} ${WRKDIR} -type f -name ltmain.sh |			\
		${XARGS} ${REINPLACE_CMD}				\
		-e 's/|-p|-pg|/|-B*|-p|-pg|/'

.if ! ${libtool_ARGS:Moldver}
	@${FIND} ${WRKDIR} \( -name configure -or -name ltconfig \)	\
		-type f | ${XARGS} ${REINPLACE_CMD}			\
		-e "/freebsd-elf\\*)/,/;;/ {				\
		    /library_names_spec=.*\\.so/			\
		    s/=.*/='\$$libname\$$release.so\$$versuffix		\
			\$$libname\$$release.so\$$major \$$libname.so'	\
		    soname_spec='\$$libname\$$release.so\$$major'/;	\
		    /library_names_spec=.*shared_ext/			\
		    s/=.*/='\$$libname\$$release\$$shared_ext\$$versuffix \
			\$$libname\$$release\$$shared_ext\$$major	\
			\$$libname\$$shared_ext'			\
		    soname_spec='\$$libname\$$release\$$shared_ext\$$major'/; }"

	@${FIND} ${WRKDIR} -type f -name ltmain.sh |			\
		${XARGS} ${REINPLACE_CMD}				\
		-e '/case $$version_type in/,+2				\
		    s/darwin|linux|/darwin|freebsd-elf|linux|/'		\
		-e '/freebsd-elf)/,+2 {					\
		    /major=/s/=.*/=.$$(($$current - $$age))/;		\
		    /versuffix=/s/=.*/="$$major.$$age.$$revision"/; }'
.endif

.endif
