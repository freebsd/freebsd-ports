# New ports collection makefile for:	Interbase 4
# Version required:			4.0
# Date created:				1998-nov-01
# Whom:					Berend de Boer <berend@pobox.com>
#
# $Id: Makefile,v 1.1.1.1 1998/12/26 08:54:56 kuriyama Exp $
#

DISTNAME=	IB_4.0_FreeBSD
PKGNAME=	interbase-4.0
CATEGORIES=	databases
MASTER_SITES=	http://iblinux.rios.co.jp/dloadfb/

MAINTAINER=	berend@pobox.com

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
		${ECHO_MSG} "Point your browser to http://iblinux.rios.co.jp/dloadfb."; \
		${ECHO_MSG} "And put the package in ${DISTDIR}."; \
		exit 1; \
	fi

do-install:
	@${MKDIR} ${IB_PATH}
	@[ -d ${PREFIX}/lib/aout ] || ${MKDIR} ${PREFIX}/lib/aout
	@chmod 777 ${IB_PATH}
	@(cd ${IB_PATH}; tar xfv ${ARCHIVE})
	@ln -sf ${IB_PATH}/include/gds.h   ${PREFIX}/include/gds.h
	@ln -sf ${IB_PATH}/include/ibase.h ${PREFIX}/include/ibase.h
.for file in gds.a gds_pyxis.a gdslib.so.0.1 gdslib.so.1.0 gdsflib.so.0.0
	@ln -sf ${IB_PATH}/lib/${file}     ${PREFIX}/lib/aout/lib${file}
.endfor
	@ln -sf ${IB_PATH}/lib/gdsintl     ${PREFIX}/lib/aout/libgdsintl.so
	@ln -sf libgdslib.so.1.0	   ${PREFIX}/lib/aout/libgdslib.so
	@${TOUCH} ${IB_PATH}/isc_event.gbl.localhost
	@chmod 777 ${IB_PATH}/isc_event.gbl.localhost
	@${ECHO} "Building Interbase sample databases."
	@${LDCONFIG} -aout -m ${PREFIX}/lib/aout
.for file in isc4.gdb help/help.gdb examples/v3/atlas.gdb examples/v3/emp.gdb examples/v4/employee.gdb examples/v4/intlemp.gdb
	@chmod uog=rw ${IB_PATH}/${file}
.endfor
	@ln -sf ${IB_PATH} /usr/interbase

.include <bsd.port.mk>
