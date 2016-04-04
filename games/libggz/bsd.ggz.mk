# $FreeBSD$

# common settings

GGZ_VERSION=	0.0.14.1

MASTER_SITES=	\
	http://mirrors.dotsrc.org/ggzgamingzone/ggz/${PORTVERSION}/ \
	http://ftp.ggzgamingzone.org/pub/ggz/${PORTVERSION}/
DIST_SUBDIR=	ggz

# components section

_USE_GGZ_ALL=	core client

core_LIB_DEPENDS=	libggz.so:games/libggz

client_LIB_DEPENDS=	libggzcore.so:games/ggz-client-libs

.for component in ${USE_GGZ}
LIB_DEPENDS+=	${${component}_LIB_DEPENDS}
. endfor

.for component in ${USE_GGZ}
. if ${_USE_GGZ_ALL:M${component}}==""
IGNORE=	cannot install: Unknown component ${component}
. endif
.endfor
