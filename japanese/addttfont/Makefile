# New ports collection makefile for:	addttfont
# Date created:		99/06/15
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	addttfont
PORTVERSION=	1.9
CATEGORIES=	japanese perl5
MASTER_SITES=	http://ftp.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/tt/
EXTRACT_SUFX=	# none

MAINTAINER=	taoka@FreeBSD.org

RUN_DEPENDS=	mkres.pl:${PORTSDIR}/japanese/p5-mkres \
		VTPSfont:${PORTSDIR}/japanese/VTPSfont \
		${X11BASE}/lib/X11/ja_JP.EUC/app-defaults/Tgif:${PORTSDIR}/japanese/tgif
#		${PREFIX}/share/ghostscript/5.50vflib/Fontmap:${PORTSDIR}/japanese/vfghostscript5
# or
#		${PREFIX}/share/ghostscript/5.10vflib/Fontmap:${PORTSDIR}/japanese/vfghostscript55

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
			${SED} -e 's;^#! */usr/bin/perl *;#!${PERL5};' \
				${DISTNAME}.orig > ${DISTNAME}

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
			${PREFIX}/bin/addttfont

.include <bsd.port.mk>
