# New ports collection makefile for:	pear-Date_Holidays
# Date created:		2006-06-16
# Whom:			Thomas Abthorpe <thomas@goodking.ca>
#
# $FreeBSD$
#

PORTNAME=	Date_Holidays
PORTVERSION=	0.21.5
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR driver based class to calculate holidays

BUILD_DEPENDS=	${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer
RUN_DEPENDS=	${PEARDIR}/Date.php:${PORTSDIR}/devel/pear-Date \
		${PEARDIR}/XML/Serializer.php:${PORTSDIR}/devel/pear-XML_Serializer

PEAR_AUTOINSTALL=	yes

LATEST_LINK=	pear-Date_Holidays
OPTIONS=	PEAR_CONSOLE_GETARGS "devel/pear-Console_Getargs" off

.include <bsd.port.pre.mk>

.if defined(PEAR_CONSOLE_GETARGS) || defined(WITH_PEAR_CONSOLE_GETARGS)
BUILD_DEPENDS+=${PEARDIR}/Console/Getargs.php:${PORTSDIR}/devel/pear-Console_Getargs
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
