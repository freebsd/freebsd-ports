# New ports collection makefile for:	Interbase 4
# Date created:				1998-nov-01
# Whom:					Berend de Boer <berend@pobox.com>
#
# $FreeBSD$
#

PORTNAME=	interbase
PORTVERSION=	4.0
CATEGORIES=	databases
MASTER_SITES=	# manual fetch
DISTNAME=	IB_4.0_FreeBSD

MAINTAINER=	berend@pobox.com

FORBIDDEN=	"Backdoored by Borland, http://www.cert.org/advisories/CA-2001-01.html for more information"
ONLY_FOR_ARCHS=	i386

NO_WRKSUBDIR=
NO_BUILD=
NO_FILTER_SHLIBS=
RESTRICTED=	"Please get distfile manually."
IS_INTERACTIVE=	"manual fetch"

IB_PATH=	${PREFIX}/interbase
ARCHIVE=	${WRKSRC}/interbase.tar

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTNAME}.tar.gz ]; then \
		${ECHO_MSG} "Sorry, this package cannot be fetched automagically."; \
		${ECHO_MSG} "Point your browser to http://iblinux.rios.co.jp/intl/dloadfb/."; \
		${ECHO_MSG} "And put the package in ${DISTDIR}."; \
		${ECHO_MSG} "IMPORTANT NOTE: a security compromise has been detected for this package."; \
		${ECHO_MSG} "Don't install this package on a server connected to the Internet or"; \
		${ECHO_MSG} "in insecure environments."; \
		${ECHO_MSG} "Read http://www.cert.org/advisories/CA-2001-01.html for more information."; \
		exit 1; \
	fi

do-install:
	@${MKDIR} ${IB_PATH}
	@[ -d ${PREFIX}/lib/aout ] || ${MKDIR} ${PREFIX}/lib/aout
	@${CHMOD} 755 ${IB_PATH}
	@(cd ${IB_PATH}; tar xfv ${ARCHIVE})
	@${LN} -sf ${IB_PATH}/include/gds.h   ${PREFIX}/include/gds.h
	@${LN} -sf ${IB_PATH}/include/ibase.h ${PREFIX}/include/ibase.h
.for file in gds.a gds_pyxis.a gdslib.so.0.1 gdslib.so.1.0 gdsflib.so.0.0
	@${LN} -sf ${IB_PATH}/lib/${file}     ${PREFIX}/lib/aout/lib${file}
.endfor
	@${LN} -sf ${IB_PATH}/lib/gdsintl     ${PREFIX}/lib/aout/libgdsintl.so
	@${LN} -sf libgdslib.so.1.0	   ${PREFIX}/lib/aout/libgdslib.so
	@${TOUCH} ${IB_PATH}/isc_event.gbl.localhost
	@${CHMOD} 644 ${IB_PATH}/isc_event.gbl.localhost
	@${ECHO} "Building Interbase sample databases."
	@${LDCONFIG} -aout -m ${PREFIX}/lib/aout
.for file in isc4.gdb help/help.gdb examples/v3/atlas.gdb examples/v3/emp.gdb examples/v4/employee.gdb examples/v4/intlemp.gdb
	@${CHMOD} uog=rw ${IB_PATH}/${file}
.endfor
	@${LN} -sf ${IB_PATH} /usr/interbase

.include <bsd.port.mk>
