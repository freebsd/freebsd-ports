# New ports collection makefile for:   Meta port of XEmacs mule with sumo package
# Version required:	21.1
# Date created:        19 August 1999
# Whom:                KIRIYAMA Kazuhiko <kiri@pis.toba-cmt.ac.jp>
#
# $FreeBSD$
#

.include	<bsd.port.pre.mk>

XEMACS_MAJOR_VER=	${.CURDIR:S!^${PORTSDIR}/japanese/xemacs!!:S!-sumo-wnn6$!!}
LANGPREFIX=		ja-
NAMEEXT=		-wnn6

MASTERDIR=	${.CURDIR}/../../editors/xemacs${XEMACS_MAJOR_VER}-mule-sumo

.include	"${MASTERDIR}/Makefile"
