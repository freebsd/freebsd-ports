# New ports collection makefile for:	ja-gqmpeg
# Date Created:		19 Sep 2001
# Whom:			TATEISHI Katsuyuki <katsu@iec.hiroshima-u.ac.jp>
#
# $FreeBSD$
#

CATEGORIES=	japanese

MAINTAINER=	katsu@iec.hiroshima-u.ac.jp

PATCH_SITES=	http://linuxlovers.yi.org/softarc/
PATCHFILES=	gqmpeg-0.9.0-jp_title.patch

MASTERDIR=	${.CURDIR}/../../audio/gqmpeg
MD5_FILE=	${.CURDIR}/distinfo
COMMENT=	${.CURDIR}/pkg-comment
DESCR=		${.CURDIR}/pkg-descr

CONFIGURE_ARGS=	--enable-japanese

NOMAN=		yes

.include "${MASTERDIR}/Makefile"
