# Handle dependency on libinotify
#
# Feature: inotify
# Valid ARGS: none
#
# inotify was added to base in FreeBSD 15, so <15 needs the
# devel/libinotify port.
#
# MAINTAINER: adamw@FreeBSD.org

.if !defined(_INCLUDE_USES_INOTIFY_MK)
_INCLUDE_USES_INOTIFY_MK=	yes

.  if exists(/usr/include/sys/inotify.h)
INOTIFY_INCLUDE_PATH=   /usr/include/sys
INOTIFY_LIB=
INOTIFY_LIB_PATH=       /usr/lib/libc.so
.  else
INOTIFY_PORT=		true
INOTIFY_INCLUDE_PATH=	${LOCALBASE}/include/sys
INOTIFY_LIB=		-linotify
INOTIFY_LIB_PATH=	${LOCALBASE}/lib/libinotify.so

LIB_DEPENDS+=	        libinotify.so:devel/libinotify
.  endif

CMAKE_ARGS+=    -DINOTIFY_INCLUDE_DIR=${INOTIFY_INCLUDE_PATH} \
                -DINOTIFY_LIBRARIES=${INOTIFY_LIB_PATH} \
                -DINOTIFY_LIBRARY=${INOTIFY_LIB_PATH} \
                -DLIBINOTIFY_INCLUDE_DIR=${INOTIFY_INCLUDE_PATH} \
                -DLIBINOTIFY_LIBRARIES=${INOTIFY_LIB_PATH} \
                -DLIBINOTIFY_LIBRARY=${INOTIFY_LIB_PATH}

.endif # !defined(_INCLUDE_USES_INOTIFY_MK)
