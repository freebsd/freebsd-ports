# New ports collection makefile for:	dnswalk
# Version required:			2.0.2
# Date created:				17 January 1998
# Whom:					Matthew Hunt <mph@pobox.com>
#
# $Id: Makefile,v 1.3 1998/09/15 21:31:49 asami Exp $

DISTNAME=	dnswalk-2.0.2
CATEGORIES=	net
MASTER_SITES=	http://www.cis.ohio-state.edu/~barr/dnswalk/

MAINTAINER=	mph@freebsd.org

RUN_DEPENDS=	${PREFIX}/lib/perl5/site_perl/${PERL_VER}/Net/DNS.pm:${PORTSDIR}/net/p5-Net-DNS

NO_WRKSUBDIR=	YES
NO_BUILD=	YES
USE_PERL5=	YES

MAN1=		dnswalk.1

EX_DIR=		${PREFIX}/share/examples/dnswalk
DOC_DIR=	${PREFIX}/share/doc/dnswalk

pre-configure:
	${MV} -f ${WRKDIR}/dnswalk ${WRKDIR}/dnswalk.orig
	${SED} -e "s#/usr/contrib/bin/perl#${PERL5}#"\
		 < ${WRKDIR}/dnswalk.orig > ${WRKDIR}/dnswalk

do-install:
	${MKDIR} ${EX_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/do-dnswalk ${EX_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/makereports ${EX_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/sendreports ${EX_DIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOC_DIR}
	${INSTALL_DATA} ${WRKDIR}/README ${DOC_DIR}
	${INSTALL_DATA} ${WRKDIR}/dnswalk.errors ${DOC_DIR}
.endif
	${INSTALL_MAN} ${WRKDIR}/dnswalk.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKDIR}/dnswalk ${PREFIX}/bin

.include <bsd.port.mk>
