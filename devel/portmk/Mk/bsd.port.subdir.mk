# $FreeBSD$

# local customization of the ports tree
.if exists(${.CURDIR}/Makefile.local)
.include "${.CURDIR}/Makefile.local"
.endif

.include "${PORTSDIR}/Mk/bsd.port.subdir.mk"
