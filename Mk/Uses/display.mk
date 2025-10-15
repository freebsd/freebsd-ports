# Feature:	display
# Usage:	USES=display or USES=display:ARGS
# Valid ARGS:	install (default, implicit), configure, build
# 
# Except the target where the DISPLAY is needed
#
# MAINTAINER: x11@FreeBSD.org

.if !defined(_INCLUDE_USES_DISPLAY_MK)
_INCLUDE_USES_DISPLAY_MK=	yes

.  if empty(display_ARGS)
display_ARGS=	install
.  endif

.  if !defined(DISPLAY)

.    if ${display_ARGS:Mconfigure}
DISPLAY_DEPENDS=	BUILD_DEPENDS
CONFIGURE_ENV+=		DISPLAY=":${XVFBPORT}"
.    elif ${display_ARGS:Mbuild}
DISPLAY_DEPENDS=	BUILD_DEPENDS
MAKE_ENV+=		DISPLAY=":${XVFBPORT}"
.    elif ${display_ARGS:Mtest}
DISPLAY_DEPENDS=	TEST_DEPENDS
TEST_ENV+=		DISPLAY=":${XVFBPORT}"
.else
IGNORE=			USES=display: invalid arguments: ${display_ARGS}
.endif

${DISPLAY_DEPENDS}+= \
	Xvfb:x11-servers/xorg-server@xvfb \
	${LOCALBASE}/share/fonts/misc/8x13O.pcf.gz:x11-fonts/xorg-fonts-miscbitmaps \
	${LOCALBASE}/share/fonts/misc/fonts.alias:x11-fonts/font-alias \
	${LOCALBASE}/share/X11/xkb/rules/base:x11/xkeyboard-config \
	xkbcomp:x11/xkbcomp

XVFBPORT?=	0
XVFBPIDFILE=	/tmp/.xvfb-${XVFBPORT}-display-mk.pid

.    for t in ${display_ARGS}
_USES_${t}+=	290:start-display 860:stop-display
.    endfor
start-display:
	pkill -15 -F ${XVFBPIDFILE} || ${TRUE}
	daemon -p ${XVFBPIDFILE} Xvfb :${XVFBPORT}

stop-display:
	pkill -15 -F ${XVFBPIDFILE}

.  endif
.endif
