# New ports collection makefile for:	perforce
# Date created:				3 Mai 2000
# Whom:					sam@inf.enst.fr
#
# $FreeBSD$
#

PORTNAME=	perforce
PORTVERSION=	00.2
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.perforce.com/pub/perforce/r${PORTVERSION}/bin.freebsd/ \
		http://www.dsmit.com/p4/ \
		ftp://ftp.perforce.com/pub/perforce/r${PORTVERSION}/doc/man/
EXTRACT_SUFX=
DISTFILES=	p4 p4d p4web p4.1 p4d.1
DIST_SUBDIR=	perforce

MAINTAINER=	sam@inf.enst.fr

NO_PACKAGE=	Restricted distribution
NO_CDROM=	Restricted distribution
MAN1=		p4.1 p4d.1

do-extract:
	@${MKDIR} ${WRKSRC}

do-build:
	${SED} -e "s,@PREFIX@,${PREFIX},g" \
		< ${FILESDIR}/perforce.sh.in > ${WRKSRC}/perforce.sh

do-install:
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/p4 ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/p4web ${PREFIX}/bin/
	${INSTALL_PROGRAM} ${DISTDIR}/${DIST_SUBDIR}/p4d ${PREFIX}/sbin/
	if [ ! -f ${PREFIX}/etc/perforce ]; then \
	  ${INSTALL_DATA} ${FILESDIR}/perforce ${PREFIX}/etc/; \
	fi
	${INSTALL_SCRIPT} ${WRKSRC}/perforce.sh ${PREFIX}/etc/rc.d/
.for PERFMAN in p4 p4d
	${INSTALL_MAN} ${DISTDIR}/${DIST_SUBDIR}/${PERFMAN}.1 ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
