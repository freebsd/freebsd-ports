# New ports collection makefile for:	skk-tools
# Version required:	9.6
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $Id$
#

DISTNAME=	skk9.6
PKGNAME=	ja-skk-tools-9.6
CATEGORIES=	japanese
MASTER_SITES=	ftp://skk.kuis.kyoto-u.ac.jp/skk/9.6/

MAINTAINER=	matusita@jp.freebsd.org

SKK_MASTERDIR=	${.CURDIR}/../../japanese/skk-jisyo
WRKSRC=		${SKK_MASTERDIR}/work/skk-9.6
MAKE_ARGS=	SUBDIRS='jisyo-tools'

do-extract:
	@echo "===>  Extracting depends on ${SKK_MASTERDIR}"
	@[ -d ${WRKDIR} ] || ${MKDIR} ${WRKDIR}
	@if [ ! -f ${SKK_MASTERDIR}/work/.extract_done ]; then \
		(cd ${SKK_MASTERDIR}; make extract) ;\
	fi
	@if [ ! -f ${SKK_MASTERDIR}/work/.configure_done ]; then \
		(cd ${SKK_MASTERDIR}; PREFIX=${PREFIX} make configure) ;\
	fi

.include <bsd.port.mk>
