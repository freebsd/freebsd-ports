# PORTNAME and CATEGORIES duplicated here, otherwise <bsd.port.options.mk> fails
PORTNAME=	gcc
CATEGORIES=	devel
PORTVERSION=	8.4.0
PKGNAMEPREFIX=	arm-none-eabi-
GCC_TARGET=	arm-none-eabi
PLIST=	${.CURDIR}/pkg-plist
DISTINFO_FILE=	${.CURDIR}/distinfo
COMMENT=	GNU Compiler Collection for bare metal arm cross-development

OPTIONS_SINGLE=	ML
OPTIONS_SINGLE_ML=	ML_NONE ML_DEFAULT ML_CORTEXA ML_CORTEXRM
OPTIONS_DEFAULT=	ML_NONE

ML_DESC=		Multilib options
ML_NONE_DESC=		Disable multilib
ML_DEFAULT_DESC=	Default multilib configuration
ML_CORTEXA_DESC=	Multilib configuration optimized for Cortex-A
ML_CORTEXRM_DESC=	Multilib configuration optimized for Cortex-M/R

# building libstdcxx would require a two-stage process
CONFIGURE_ARGS=	--disable-libstdcxx \
	--without-headers

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MML_NONE}
CONFIGURE_ARGS+=	--disable-multilib
PLIST_SUB+=		ML_DEFAULT="@comment " ML_CORTEX="@comment " ML_CORTEXA="@comment " ML_CORTEXRM="@comment "
SUB_LIST+=		ML_DEFAULT="@comment " ML_CORTEX="@comment " ML_CORTEXA="@comment " ML_CORTEXRM="@comment "
.endif
.if ${PORT_OPTIONS:MML_DEFAULT}
CONFIGURE_ARGS+=	--enable-multilib
PLIST_SUB+=		ML_DEFAULT="" ML_CORTEX="@comment " ML_CORTEXA="@comment " ML_CORTEXRM="@comment "
SUB_LIST+=		ML_DEFAULT="" ML_CORTEX="@comment " ML_CORTEXA="@comment " ML_CORTEXRM="@comment "
.endif
.if ${PORT_OPTIONS:MML_CORTEXA}
CONFIGURE_ARGS+=	--enable-multilib --with-multilib-list=aprofile
PLIST_SUB+=		ML_DEFAULT="@comment " ML_CORTEX="" ML_CORTEXA="" ML_CORTEXRM="@comment "
SUB_LIST+=		ML_DEFAULT="@comment " ML_CORTEX="" ML_CORTEXA="" ML_CORTEXRM="@comment "
.endif
.if ${PORT_OPTIONS:MML_CORTEXRM}
CONFIGURE_ARGS+=	--enable-multilib --with-multilib-list=rmprofile
PLIST_SUB+=		ML_DEFAULT="@comment " ML_CORTEX="" ML_CORTEXA="@comment " ML_CORTEXRM=""
SUB_LIST+=		ML_DEFAULT="@comment " ML_CORTEX="" ML_CORTEXA="@comment " ML_CORTEXRM=""
.endif

MASTERDIR=	${.CURDIR}/../aarch64-none-elf-gcc

.include "${MASTERDIR}/Makefile"
