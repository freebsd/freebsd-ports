# New ports collection makefile for:    cups-fr
# Date created:                         08 June 2002
# Whom:                                 James Halstead <jah4007@cs.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	cups
PORTVERSION=	${CUPS_PORTVER}
CATEGORIES=	french print

MAINTAINER=	AlanE@FreeBSD.org

LIB_DEPENDS=	cups.2:${.CURDIR}/../../french/cups-base
RUN_DEPENDS=	${LOCALBASE}/sbin/cupsaddsmb:${.CURDIR}/../../french/cups-lpr

CUPS_FR=	yes
MASTERDIR=	${.CURDIR}/../../print/cups

.include "${MASTERDIR}/Makefile"
