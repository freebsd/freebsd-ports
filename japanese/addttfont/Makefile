# New ports collection makefile for:	addttfont
# Date created:		99/06/15
# Whom:			Satoshi TAOKA <taoka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	addttfont
PORTVERSION=	1.11
PORTREVISION=	1
CATEGORIES=	japanese perl5
MASTER_SITES=	http://ftp.infonets.hiroshima-u.ac.jp/~taoka/FreeBSD/tt/
EXTRACT_SUFX=	# none

MAINTAINER=	taoka@FreeBSD.org
COMMENT=	Automatically create a Japanese font environment by TrueType fonts

RUN_DEPENDS=	mkres.pl:${PORTSDIR}/japanese/p5-mkres \
		${X11BASE}/lib/X11/ja_JP.eucJP/app-defaults/Tgif:${PORTSDIR}/japanese/tgif \
		${PREFIX}/share/ghostscript/7.07/lib/CIDFnmap.jp:${PORTSDIR}/japanese/ghostscript-gnu-jpnfont

#		VTPSfont:${PORTSDIR}/japanese/VTPSfont \
#		${PREFIX}/share/ghostscript/5.50vflib/Fontmap:${PORTSDIR}/japanese/vfghostscript55
# or
#		${PREFIX}/share/ghostscript/5.10vflib/Fontmap:${PORTSDIR}/japanese/vfghostscript5

PLIST_FILES=	bin/addttfont
USE_PERL5=	yes
NO_WRKSUBDIR=	yes

VFLIB_VERSION=  2.25.6

do-extract:
		${RM} -rf ${WRKDIR}
		${MKDIR} ${WRKDIR}
		for file in ${DISTFILES}; do \
			${CP} ${DISTDIR}/${DIST_SUBDIR}/$${file} ${WRKSRC}; \
		done

do-build:
		cd ${WRKSRC}; ${MV} ${DISTNAME} ${DISTNAME}.orig; \
			${SED}	-e 's;^#! */usr/bin/perl *;#!${PERL5};' \
				-e 's;/share/VFlib/2.25.2/vfontcap;/share/VFlib/${VFLIB_VERSION}/vfontcap;' \
				${DISTNAME}.orig > ${DISTNAME}

do-install:
		${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
			${PREFIX}/bin/addttfont

.include <bsd.port.mk>
