# $FreeBSD$
#
# Bring libtool scripts up to date.
#
# MAINTAINER:	autotools@FreeBSD.org
#
# Feature:	libtool
# Usage:	USES=libtool

.if !defined(_INCLUDE_USES_LIBTOOL_MK)
_INCLUDE_USES_LIBTOOL_MK=	yes
_USES_POST+=	libtool
libtool_ARGS?=
.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_LIBTOOL_POST_MK)
_INCLUDE_USES_LIBTOOL_POST_MK=	yes

patch-libtool:
	@${FIND} ${WRKDIR} -type f -name configure |			\
		${XARGS} ${REINPLACE_CMD}				\
		-e '/link_all_deplibs=/s/=unknown/=no/'			\
		-e '/objformat=/s/echo aout/echo elf/'

.if ! ${libtool_ARGS:Moldver}
	@${FIND} ${WRKDIR} -type f -name configure |			\
		${XARGS} ${REINPLACE_CMD}				\
		-e "/freebsd-elf\*)/,+1 s/library_names_spec=.*/	\
		    library_names_spec='\$$libname\$$release.so\$$versuffix \
			\$$libname\$$release.so\$$major	\$$libname.so'	\
		    soname_spec='\$$libname\$$release.so\$$major'/"

	@${FIND} ${WRKDIR} -type f -name ltmain.sh |			\
		${XARGS} ${REINPLACE_CMD}				\
		-e '/case $$version_type in/,+2				\
		    s/darwin|linux|/darwin|freebsd-elf|linux|/'		\
		-e '/freebsd-elf)/,+2 {					\
		    /major=/s/=.*/=.$$(($$current - $$age))/;		\
		    /versuffix=/s/=.*/="$$major.$$age.$$revision"/; }'
.endif

.endif
