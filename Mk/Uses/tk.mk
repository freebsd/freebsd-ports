# $FreeBSD$
#
# vim: ts=8 noexpandtab
#

.if defined(tk_ARGS)
tcl_ARGS:=	${tk_ARGS}
.endif

_TCLTK_PORT=	tk

.include "${PORTSDIR}/Mk/Uses/tcl.mk"
