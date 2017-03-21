# $FreeBSD$
#
# Handle dependency on samba
#
# Feature:	samba
# Usage:	USES=samba or USES=samba:ARGS
# Valid ARGS:	build, env, lib, run
#		default is build,run (implicit)
#
# When subpackages are available this can be more granular
#

.if !defined(_INCLUDE_USES_SAMBA_MK)
_INCLUDE_USES_SAMBA_MK=   yes

.if !${samba_ARGS}
samba_ARGS=	build run
.endif

.if ${samba_ARGS:Nbuild:Nenv:Nlib:Nrun}
IGNORE=		USES=samba has invalid arguments: ${samba_ARGS:Nbuild:Nenv:Nlib:Nrun}
.endif

.if ${SAMBA_DEFAULT} == 4.2
SAMBAINCLUDES=	${LOCALBASE}/include/samba4
SAMBALIBS=	${LOCALBASE}/lib
SAMBAPORT=	net/samba42
.elif ${SAMBA_DEFAULT} == 4.3
SAMBAINCLUDES=	${LOCALBASE}/include/samba4
SAMBALIBS=	${LOCALBASE}/lib
SAMBAPORT=	net/samba43
.elif ${SAMBA_DEFAULT} == 4.4
SAMBAINCLUDES=	${LOCALBASE}/include/samba4
SAMBALIBS=	${LOCALBASE}/lib/samba4
SAMBAPORT=	net/samba44
.else
IGNORE=		Invalid version of samba: ${SAMBA_DEFAULT}
.endif

.if ${samba_ARGS:Mbuild}
BUILD_DEPENDS+=	smbd:${SAMBAPORT}
.endif
.if ${samba_ARGS:Mlib}
LIB_DEPENDS+=	libsmbclient.so:${SAMBAPORT}
.endif
.if ${samba_ARGS:Mrun}
RUN_DEPENDS+=	smbd:${SAMBAPORT}
.endif

.endif

