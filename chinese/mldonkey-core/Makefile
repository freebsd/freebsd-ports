# New ports collection makefile for:	zh-tw-mldonkey
# Date created:				Wed Mar 10 19:36:06 CST 2004
# Whom:					Hung-Te Lin
#                                       <piaip@csie.ntu.edu.tw>
#
# $FreeBSD$
#
# Only core (HTML/telnet) is affected. GUI has no problem with Chinese.

PORTNAME=	mldonkey-core
CATEGORIES=	chinese

MAINTAINER=	piaip@csie.ntu.edu.tw
COMMENT=	Client 'core' for MLDonkey with Traditional Chinese (Big5) support

WITHOUT_GUI=	yes
MASTERDIR=	${.CURDIR}/../../net/mldonkey
EXTRA_PATCHES=	${.CURDIR}/files/patch-driverControlers.ml

.include "${MASTERDIR}/Makefile"

PKGNAMEPREFIX:= ${PKGNAMEPREFIX}tw-
