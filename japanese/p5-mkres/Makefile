# New ports collection makefile for:	mkres.pl
# Version required:	0.6
# Date created:		29 Jun 1998
# Whom:			Satoshi TAOKA <taoka@infonets.hiroshima-u.ac.jp>
#
# $Id$
#

DISTNAME=	mkres.pl-0.6
PKGNAME=	ja-p5-mkres-0.6
CATEGORIES=	japanese perl5
MASTER_SITES=	http://ftp.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/tt/
EXTRACT_SUFX=	''

MAINTAINER=	taoka@infonets.hiroshima-u.ac.jp

RUN_DEPENDS=	mkttfdir.pl:${PORTSDIR}/x11/p5-mkttfdir

USE_PERL5=	yes
NO_WRKSUBDIR=	yes

do-extract:
		@${RM} -rf ${WRKDIR}
		@${MKDIR} ${WRKDIR}
		@for file in ${DISTFILES}; do \
			${CP} ${DISTDIR}/${DIST_SUBDIR}/$${file} ${WRKSRC}; \
		done

do-build:
		@cd ${WRKSRC}; ${MV} ${DISTNAME} ${DISTNAME}.orig; \
			${SED} -e 's;^#! */usr/local/bin/perl *;#!${PERL5};' \
				${DISTNAME}.orig > ${DISTNAME}

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
			${PREFIX}/bin/mkres.pl

.include <bsd.port.mk>
