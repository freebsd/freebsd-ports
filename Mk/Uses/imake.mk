# $FreeBSD$
#
# Provide support for imake based projects
#
# Feature:		imake
# Usage:		USES=imake
# Valid ARGS:		env: do not define any target
#			notall: do not pass -a to xmkmf
#			noman: do not add install-man to
#			INSTALL_TARGET
#
# MAINTAINER: x11@FreeBSD.org

.if !defined(_INCLUDE_USES_IMAKE_MK)
_INCLUDE_USES_IMAKE_MK=	yes

.if ${imake_ARGS:Nnotall:Nenv:Nnoman}
IGNORE=		USES=imake:${imake_ARGS:S/ /,/g} is not a valid argument
.endif

BUILD_DEPENDS+=		imake:${PORTSDIR}/devel/imake

.if defined(USE_GCC)
IMAKECPP=		${CPP}
IMAKECPPFLAGS=		-DCppCmd=${CPP} -DCcCmd=${CC} -DCplusplusCmd=${CXX}
.else
IMAKECPP=		tradcpp
IMAKECPPFLAGS=		-DCppCmd=tradcpp -DCcCmd=${CC} -DCplusplusCmd=${CXX}
BUILD_DEPENDS+=		tradcpp:${PORTSDIR}/devel/tradcpp
.endif
MAKE_ENV+=		IMAKECPP=${IMAKECPP} IMAKECPPFLAGS="${IMAKECPPFLAGS}"
CONFIGURE_ENV+=		IMAKECPP=${IMAKECPP} IMAKECPPFLAGS="${IMAKECPPFLAGS}"

.if ! ${imake_ARGS:Mnotall}
XMKMF_ARGS+=		-a
.endif

.if ! ${imake_ARGS:Menv}
.if !target(do-configure)
do-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${MAKE_ENV} ${XMKMF} ${XMKMF_ARGS})
.endif

.if ! ${imake_ARGS:Mnoman}
LATE_INSTALL_ARGS=	install.man
.endif

.endif

.endif
