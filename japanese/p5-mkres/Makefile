# New ports collection makefile for:	mkres.pl
# Date created:		29 Jun 1998
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mkres
PORTVERSION=	1.6
CATEGORIES=	japanese perl5
MASTER_SITES=	http://ftp.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/tt/
EXTRACT_SUFX=	# none
DISTNAME=	${PORTNAME}.pl-${PORTVERSION}

MAINTAINER=	taoka@FreeBSD.org
COMMENT=	Create resources for tgif, vfontcap, .., for Japanese TrueType fonts

RUN_DEPENDS=	mkttfdir:${PORTSDIR}/print/perlftlib

PLIST_FILES=	bin/mkres.pl
USE_PERL5=	yes
NO_WRKSUBDIR=	yes

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

do-extract:
		@${RM} -rf ${WRKDIR}
		@${MKDIR} ${WRKDIR}
		@for file in ${DISTFILES}; do \
			${CP} ${DISTDIR}/${DIST_SUBDIR}/$${file} ${WRKSRC}; \
		done

do-build:
		@cd ${WRKSRC}; ${MV} ${DISTNAME} ${DISTNAME}.orig; \
			${SED} -e 's;^#! */usr/bin/perl *;#!${PERL5};' \
				${DISTNAME}.orig > ${DISTNAME}

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
			${PREFIX}/bin/mkres.pl

.include <bsd.port.post.mk>
