# New ports collection makefile for:	Science and Industry Server
# Date created:				Tue May  1 23:40:46 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	si
PORTVERSION=	0.97.0ra
PORTREVISION=	1
MASTER_SITES=	http://bsd.gubkin.ru/myports/ \
		http://mirror.isp.net.au/ftp/pub/FreeBSD/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g:S/0r//}-linux

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Half-Life mod Science and Industry full server package for Linux

_DONT_INCLUDE_MK_=yes

HALFLIFE_PORT_MASTER=	${.CURDIR}/../hlserver-flf

.include "${HALFLIFE_PORT_MASTER}/Makefile"

.include <bsd.port.mk>
