# $FreeBSD$
#
# Provide support for imake based projects
#
# MAINTAINER: x11@FreeBSD.org
#
# Feature:		imake
# Usage:		USES=imake
# Valid ARGS:		env: do not define any target
#

.if !defined(_INCLUDE_USES_IMAKE_MK)
_INCLUDE_USES_IMAKE_MK=	yes

.if defined(imake_ARGS)
.if ${imake_ARGS} == env
IMAKE_ENV_ONLY=	yes
.else
IGNORE=		USES=imake ${imake_ARGS} is not a valid argument
.endif
.endif

.if !defined(NO_INSTALL_MANPAGES)
MANCOMPRESSED?=	yes
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
MAKE_ARGS+=		IMAKE_DEFINES="${IMAKECPPFLAGS}"

.if !defined(IMAKE_ENV_ONLY)
.if !target(do-configure)
do-configure:
	@(cd ${CONFIGURE_WRKSRC}; ${SETENV} ${MAKE_ENV} ${XMKMF})
.endif

.if !defined(NO_INSTALL_MANPAGES)
LATE_INSTALL_ARGS=	install.man
.endif

.endif

.endif
