# New ports collection makefile for:	screamer
# Date created:				Jun 26 2002
# Whom:					Scott Flatman <sf@dsinw.com>
#
# $FreeBSD$
#

PORTNAME=	screamer
PORTVERSION=	3.20
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/ \
		${MASTER_SITE_LOCAL}
DISTNAME=	screamer.tar
EXTRACT_SUFX=	.Z

MAINTAINER=	sf@slappy.org
COMMENT=	Extension of Common Lisp for nondeterministic programming

BUILD_DEPENDS=	lisp:${PORTSDIR}/lang/cmucl
RUN_DEPENDS=	${LOCALBASE}/bin/lisp:${PORTSDIR}/lang/cmucl

NO_BUILD=	yes

pre-install:
	(cd ${WRKDIR}/screamer && ${LOCALBASE}/bin/lisp -eval '(load "${FILESDIR}/build.lisp")')

do-install:
	(cd ${WRKDIR}/screamer ; ${MV} screamer.x86f ${PREFIX}/lib/cmucl/lib/subsystems/screamer-library.x86f)
	${CHMOD} 644 ${PREFIX}/lib/cmucl/lib/subsystems/screamer-library.x86f
	-${MKDIR} ${PREFIX}/share/screamer
	(cd ${WRKDIR} && tar fc - screamer) | (cd ${PREFIX}/share && tar fx -)
	(cd ${PREFIX}/share/screamer ; ${CHMOD} 644 *)

post-install:
	@echo "To load screamer into a lisp session:"
	@echo "  (1) invoke lisp"
	@echo "  (2) (require 'screamer)"
	@echo "${PREFIX}/share/screamer constains source and documentation."

.include <bsd.port.mk>
